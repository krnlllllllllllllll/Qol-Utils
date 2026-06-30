#include <Geode/Geode.hpp>
#include <Geode/ui/Popup.hpp>
#include <Geode/ui/ScrollLayer.hpp>
#include <Geode/ui/GeodeUI.hpp>

using namespace geode::prelude;

// Simple popup base for editor tools
class EditorToolPopup : public Popup {
public:
    static EditorToolPopup* create(const char* title) {
        auto ret = new EditorToolPopup();
        if (ret && ret->init(320.f, 260.f, title)) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }

    bool setup() override {
        auto label = CCLabelBMFont::create(
            "Configure this editor tool in QOL Utils.",
            "bigFont.fnt"
        );
        label->setPosition({160.f, 220.f});
        this->addChild(label);
        return true;
    }
};

// Main custom setting node: Editor Tools hub
class MyCustomSettingV3 : public SettingNode {
public:
    static MyCustomSettingV3* create() {
        auto ret = new MyCustomSettingV3();
        if (ret && ret->init()) {
            ret->autorelease();
            return ret;
        }
        CC_SAFE_DELETE(ret);
        return nullptr;
    }

    bool init() override {
        if (!SettingNode::init()) return false;

        auto menu = CCMenu::create();
        menu->setPosition({0.f, 0.f});
        this->addChild(menu);

        float y = 140.f;
        float xLeft = 80.f;
        float xRight = 240.f;
        float dy = 26.f;

        // 1. AI Layout Generator (Playtest)
        addButton(menu, "AI Layout Generator", xLeft, y, menu_selector(MyCustomSettingV3::onAILayout));
        y -= dy;

        // 2. Auto-Structure Builder
        addButton(menu, "Auto Structure Builder", xLeft, y, menu_selector(MyCustomSettingV3::onAutoStructure));
        y -= dy;

        // 3. Pattern Repeater
        addButton(menu, "Pattern Repeater", xLeft, y, menu_selector(MyCustomSettingV3::onPatternRepeater));
        y -= dy;

        // 4. Smart Deco Filler
        addButton(menu, "Smart Deco Filler", xLeft, y, menu_selector(MyCustomSettingV3::onSmartDeco));
        y -= dy;

        // 5. Auto Group Assigner
        addButton(menu, "Auto Group Assigner", xLeft
