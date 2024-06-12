#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/LevelSearchLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, LevelSearchLayer) {
public:
    bool init(int p0) {
        if (!LevelSearchLayer::init(p0)) {
            return false;
        }

        auto myButton = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_profileButton_001.png"),
            this,
            menu_selector(MyMenuLayer::onMyButton)
            
        );
myButton->setScale(0.7);
        

        auto menu = this->getChildByID("other-filter-menu");


        menu->addChild(myButton);

        myButton->setID("mod-button"_spr);
        myButton->setScale(0.7);
        menu->updateLayout();

        return true;
    }

    void onMyButton(CCObject* sender) {
        auto myButton = dynamic_cast< CCMenuItemSpriteExtra*>(sender);
        if (myButton) {
            myButton->setScale(0.7);
        }

        std::vector<int> moderatorIDs = {7560014, 489692, 1086146, 1093804, 906671, 2465705, 2517174, 1705254, 248526, 71, 57903, 3331655, 10840, 2795, 938808, 98006, 571210, 1293622, 2816040, 1449207, 5583, 201646, 7623534, 3392, 408, 710192, 6768299, 6328600, 1775477, 5052529, 16460, 5890735, 7476439, 883621, 13364, 272294, 4861064, 1403996, 5151647, 1711800, 102968, 5367295, 104497, 5629061, 2317322, 7009582, 5871590, 2010390, 811343, 1275405, 2638799, 3541866, 5930381, 2358957, 1373926, 947652, 2379669, 7212066, 3220546, 6061424, 7346996, 5981309, 11050898, 13736998, 4401746, 133104, 10634948, 1521580, 7085748, 1086146, 755272, 17025968, 3392, 4712395, 3772205, 7960556, 1788352, 11176072, 2657593, 3090197, 470, 5603162};
        int randomIndex = rand() % moderatorIDs.size();
        int randomID = moderatorIDs[randomIndex];

        auto popupCallback = [randomID](auto, int index) {
            if (index == 1) {
            } else if (index == 0) {
                ProfilePage::create(randomID, false)->show();
            }
        };

        geode::createQuickPopup(
            "Random Moderator",
            "Let fate choose your moderator!",
            "Randomize", "Exit",
            popupCallback
        );
    }
};
