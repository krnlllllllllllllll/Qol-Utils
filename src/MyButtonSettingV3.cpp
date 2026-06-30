#include <Geode/Geode.hpp>
#include <Geode/ui/Popup.hpp>
#include <Geode/ui/ScrollLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;

class PlaytestMenu : public Popup {
public:
    static PlaytestMenu* create() {
        auto ret = new PlaytestMenu();
        if (ret && ret->init(300.f, 240.f, "AI Layout Generator")) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }

    bool setup() override {
        this->setTitle("AI Layout Generator");

        auto winSize = CCDirector::sharedDirector()->getWinSize();

        auto label = CCLabelBMFont::create(
            "Configure your AI-generated layout",
            "bigFont.fnt"
        );
        label->setPosition({150.f, 200.f});
        this->addChild(label);

        // Example setting: difficulty slider
        auto difficulty = Slider::create(
            0.f, 1.f, 0.5f,
            [](float value) {
                log::info("AI difficulty set to {}", value);
            }
        );
        difficulty->setPosition({150.f, 150.f});
        this->addChild(difficulty);

        // Example setting: length selector
        auto lengthBtn = ButtonSprite::create("Length: Medium", "bigFont.fnt", "GJ_button_01.png");
        auto length = CCMenuItemSpriteExtra::create(
            lengthBtn, this, menu_selector(PlaytestMenu::onLength)
        );
        length->setPosition({150.f, 110.f});
        this->m_buttonMenu->addChild(length);

        // Generate button
        auto generateBtn = ButtonSprite::create("Generate Layout", "bigFont.fnt", "GJ_button_01.png");
        auto generate = CCMenuItemSpriteExtra::create(
            generateBtn, this, menu_selector(PlaytestMenu::onGenerate)
        );
        generate->setPosition({150.f, 60.f});
        this->m_buttonMenu->addChild(generate);

        return true;
    }

    void onLength(CCObject*) {
        log::info("Layout length changed");
    }

    void onGenerate(CCObject*) {
        log::info("Running AI layout generator…");

        // Call your AI generator here
        // Example:
        // auto layout = AI::generateLayout(difficultyValue, lengthValue);
        // Editor::applyLayout(layout);

        FLAlertLayer::create(
            "AI Generator",
            "Your layout has been generated and applied!",
            "OK"
        )->show();
    }
};

class MyButtonSettingV3 : public SettingNode {
public:
    bool init() override {
        if (!SettingNode::init()) return false;

        auto btnSprite = ButtonSprite::create("Playtest", "bigFont.fnt", "GJ_button_01.png");
        auto btn = CCMenuItemSpriteExtra::create(
            btnSprite, this, menu_selector(MyButtonSettingV3::onPlaytest)
        );

        auto menu = CCMenu::create();
        menu->addChild(btn);
        menu->setPosition({50.f, 20.f});
        this->addChild(menu);

        return true;
    }

    void onPlaytest(CCObject*) {
        PlaytestMenu::create()->show();
    }
};
