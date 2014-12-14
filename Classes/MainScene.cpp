#include "MainScene.h"
#include "spine/Json.h"

#include <SimpleAudioEngine.h>
//using namespace extension;
using namespace cocos2d::network;

#define ENABLE_MOVE_ITEM false

static const float itemOffset = 160;

static const Code2ISOMap c2is = {
    Code2ISO("AED", AED),
    Code2ISO("AFN", AFN),
    Code2ISO("ALL", ALL),
    Code2ISO("AMD", AMD),
    Code2ISO("ANG", ANG),
    Code2ISO("AOA", AOA),
    Code2ISO("ARS", ARS),
    Code2ISO("AUD", AUD),
    Code2ISO("AWG", AWG),
    Code2ISO("AZN", AZN),
    Code2ISO("BAM", BAM),
    Code2ISO("BBD", BBD),
    Code2ISO("BDT", BDT),
    Code2ISO("BGN", BGN),
    Code2ISO("BHD", BHD),
    Code2ISO("BIF", BIF),
    Code2ISO("BMD", BMD),
    Code2ISO("BND", BND),
    Code2ISO("BOB", BOB),
    Code2ISO("BRL", BRL),
    Code2ISO("BSD", BSD),
    Code2ISO("BTN", BTN),
    Code2ISO("BWP", BWP),
    Code2ISO("BYR", BYR),
    Code2ISO("BZD", BZD),
    Code2ISO("CAD", CAD),
    Code2ISO("CDF", CDF),
    Code2ISO("CHF", CHF),
    Code2ISO("CLP", CLP),
    Code2ISO("CNY", CNY),
    Code2ISO("COP", COP),
    Code2ISO("CRC", CRC),
    Code2ISO("CSD", CSD),
    Code2ISO("CUC", CUC),
    Code2ISO("CUP", CUP),
    Code2ISO("CVE", CVE),
    Code2ISO("CZK", CZK),
    Code2ISO("DJF", DJF),
    Code2ISO("DKK", DKK),
    Code2ISO("DOP", DOP),
    Code2ISO("DZD", DZD),
    Code2ISO("EGP", EGP),
    Code2ISO("ERN", ERN),
    Code2ISO("ETB", ETB),
    Code2ISO("EUR", EUR),
    Code2ISO("FJD", FJD),
    Code2ISO("FKP", FKP),
    Code2ISO("GBP", GBP),
    Code2ISO("GEL", GEL),
    Code2ISO("GGP", GGP),
    Code2ISO("GHS", GHS),
    Code2ISO("GIP", GIP),
    Code2ISO("GMD", GMD),
    Code2ISO("GNF", GNF),
    Code2ISO("GTQ", GTQ),
    Code2ISO("GYD", GYD),
    Code2ISO("HKD", HKD),
    Code2ISO("HNL", HNL),
    Code2ISO("HRK", HRK),
    Code2ISO("HTG", HTG),
    Code2ISO("HUF", HUF),
    Code2ISO("IDR", IDR),
    Code2ISO("ILS", ILS),
    Code2ISO("INR", INR),
    Code2ISO("IQD", IQD),
    Code2ISO("IRR", IRR),
    Code2ISO("ISK", ISK),
    Code2ISO("JMD", JMD),
    Code2ISO("JOD", JOD),
    Code2ISO("JPY", JPY),
    Code2ISO("KES", KES),
    Code2ISO("KGS", KGS),
    Code2ISO("KHR", KHR),
    Code2ISO("KMF", KMF),
    Code2ISO("KPW", KPW),
    Code2ISO("KRW", KRW),
    Code2ISO("KWD", KWD),
    Code2ISO("KYD", KYD),
    Code2ISO("KZT", KZT),
    Code2ISO("LAK", LAK),
    Code2ISO("LBP", LBP),
    Code2ISO("LKR", LKR),
    Code2ISO("LRD", LRD),
    Code2ISO("LSL", LSL),
    Code2ISO("LTL", LTL),
    Code2ISO("LYD", LYD),
    Code2ISO("MAD", MAD),
    Code2ISO("MDL", MDL),
    Code2ISO("MGA", MGA),
    Code2ISO("MKD", MKD),
    Code2ISO("MMK", MMK),
    Code2ISO("MNT", MNT),
    Code2ISO("MOP", MOP),
    Code2ISO("MRO", MRO),
    Code2ISO("MUR", MUR),
    Code2ISO("MVR", MVR),
    Code2ISO("MWK", MWK),
    Code2ISO("MXN", MXN),
    Code2ISO("MYR", MYR),
    Code2ISO("MZN", MZN),
    Code2ISO("NAD", NAD),
    Code2ISO("NGN", NGN),
    Code2ISO("NIO", NIO),
    Code2ISO("NOK", NOK),
    Code2ISO("NPR", NPR),
    Code2ISO("NZD", NZD),
    Code2ISO("OMR", OMR),
    Code2ISO("PAB", PAB),
    Code2ISO("PEN", PEN),
    Code2ISO("PGK", PGK),
    Code2ISO("PHP", PHP),
    Code2ISO("PKR", PKR),
    Code2ISO("PLN", PLN),
    Code2ISO("PYG", PYG),
    Code2ISO("QAR", QAR),
    Code2ISO("RON", RON),
    Code2ISO("RUB", RUB),
    Code2ISO("RWF", RWF),
    Code2ISO("SAR", SAR),
    Code2ISO("SBD", SBD),
    Code2ISO("SCR", SCR),
    Code2ISO("SDG", SDG),
    Code2ISO("SEK", SEK),
    Code2ISO("SGD", SGD),
    Code2ISO("SHP", SHP),
    Code2ISO("SLL", SLL),
    Code2ISO("SOS", SOS),
    Code2ISO("SRD", SRD),
    Code2ISO("SSP", SSP),
    Code2ISO("STD", STD),
    Code2ISO("SVC", SVC),
    Code2ISO("SYP", SYP),
    Code2ISO("SZL", SZL),
    Code2ISO("THB", THB),
    Code2ISO("TJS", TJS),
    Code2ISO("TMT", TMT),
    Code2ISO("TND", TND),
    Code2ISO("TOP", TOP),
    Code2ISO("TRY", TRY),
    Code2ISO("TTD", TTD),
    Code2ISO("TWD", TWD),
    Code2ISO("TZS", TZS),
    Code2ISO("UAH", UAH),
    Code2ISO("UGX", UGX),
    Code2ISO("USD", USD),
    Code2ISO("UYU", UYU),
    Code2ISO("UZS", UZS),
    Code2ISO("VEF", VEF),
    Code2ISO("VND", VND),
    Code2ISO("VUV", VUV),
    Code2ISO("WST", WST),
    Code2ISO("XAF", XAF),
    Code2ISO("XAG", XAG),
    Code2ISO("XAU", XAU),
    Code2ISO("XCD", XCD),
    Code2ISO("XDR", XDR),
    Code2ISO("XOF", XOF),
    Code2ISO("XPD", XPD),
    Code2ISO("XPF", XPF),
    Code2ISO("XPT", XPT),
    Code2ISO("XTS", XTS),
    Code2ISO("XXX", XXX),
    Code2ISO("YER", YER),
    Code2ISO("ZAR", ZAR),
    Code2ISO("ZMK", ZMK),
    Code2ISO("ZWD", ZWD),
};

static const ISOInfoMap isoInfoMap = {
    ISOInfoPair(GBP, ISOInfo{ GBP, "£", "UKポンド", "gbp.png" }),
    ISOInfoPair(NZD, ISOInfo{ NZD, "$", "ニュージーランド・ドル", "nzd.png" }),
    ISOInfoPair(CAD, ISOInfo{ CAD, "$", "カナダ・ドル", "cad.png" }),
    ISOInfoPair(JPY, ISOInfo{ JPY, "¥", "日本円", "jpy.png" }),
    ISOInfoPair(AUD, ISOInfo{ AUD, "$", "オーストラリア・ドル", "aud.png" }),
    ISOInfoPair(EUR, ISOInfo{ EUR, "€", "ユーロ", "eur.png" }),
    ISOInfoPair(USD, ISOInfo{ USD, "$", "アメリカ合衆国ドル", "usd.png" }),
    ISOInfoPair(ZAR, ISOInfo{ ZAR, "R", "ランド", "zar.png" }),
    ISOInfoPair(CHF, ISOInfo{ CHF, "₣", "スイス・フラン", "chf.png" }),
};

static const CalcButton::Data calcDatas[] = {
    { CalcButton::Decimal, 0, Color3B(127,127,127), ".", "calc160x160.png", Point(80+320,80) },
    { CalcButton::Num, 0, Color3B(127,127,127), "０", "calc160x160.png", Point(80+160,80) },
    { CalcButton::Num, 1, Color3B(127,127,127), "１", "calc160x160.png", Point(80,80+160) },
    { CalcButton::Num, 2, Color3B(127,127,127), "２", "calc160x160.png", Point(80+160,80+160) },
    { CalcButton::Num, 3, Color3B(127,127,127), "３", "calc160x160.png", Point(80+320,80+160) },
    { CalcButton::Num, 4, Color3B(127,127,127), "４", "calc160x160.png", Point(80,80+320) },
    { CalcButton::Num, 5, Color3B(127,127,127), "５", "calc160x160.png", Point(80+160,80+320) },
    { CalcButton::Num, 6, Color3B(127,127,127), "６", "calc160x160.png", Point(80+320,80+320) },
    { CalcButton::Num, 7, Color3B(127,127,127), "７", "calc160x160.png", Point(80,80+480) },
    { CalcButton::Num, 8, Color3B(127,127,127), "８", "calc160x160.png", Point(80+160,80+480) },
    { CalcButton::Num, 9, Color3B(127,127,127), "９", "calc160x160.png", Point(80+320,80+480) },
    { CalcButton::Add, 0, Color3B(255,127,0), "+", "calc160x160.png", Point(80+480,80+640) },
    { CalcButton::Sub, 0, Color3B(255,127,0), "−", "calc160x160.png", Point(80+480,80+480) },
    { CalcButton::Mul, 0, Color3B(255,127,0), "×", "calc160x160.png", Point(80+480,80+320) },
    { CalcButton::Div, 0, Color3B(255,127,0), "÷", "calc160x160.png", Point(80+480,80+160) },
    { CalcButton::Clear, 0, Color3B(255,127,0), "c", "calc160x160.png", Point(80+320,80+640) },
    { CalcButton::Equal, 0, Color3B(255,127,0), "=", "calc160x160.png", Point(80+480,80) },
    { CalcButton::Delete, 0, Color3B(255,127,0), "del", "calc160x160.png", Point(80+160,80+640) },
    { CalcButton::Decide, 0, Color3B(0,255,0), "換算", "calc160x160.png", Point(80,80) },
    { CalcButton::Cancel, 0, Color3B(0,0,255), "戻る", "calc160x160.png", Point(80,80+640) },
    { CalcButton::None }
};

static const MotionSpriteMap motionSpriteMap = {
    MotionSpritePair( Main::MotionNormal,       "kc_01_default.png" ),
    MotionSpritePair( Main::MotionPointing,     "kc_02_ubi.png" ),
    MotionSpritePair( Main::MotionArmsCross,    "kc_03_ude.png" ),
    MotionSpritePair( Main::MotionMatroos,      "kc_04_sea.png" ),
};

static const std::vector<MessageMotion> messageMotions = {
    { "はぁ！",            Main::MotionArmsCross },
    { "なんだよ",          Main::MotionNormal },
    { "なにやってんだよ！", Main::MotionPointing },
    { "またかよ",          Main::MotionPointing },
    { "下がった",          Main::MotionMatroos },
    { "踏むよ！",          Main::MotionPointing },
    { "めんどくせ〜な",     Main::MotionArmsCross },
    { "もういいだろ",       Main::MotionArmsCross },
    { "見んな",            Main::MotionArmsCross },
    { "終わり",            Main::MotionMatroos },
    { "ぶっとばす",         Main::MotionPointing },
    { "キモイ",            Main::MotionNormal },
    { "明日にしろ",        Main::MotionNormal },
    { "なんすか？",        Main::MotionArmsCross },
    { "ダメ",             Main::MotionArmsCross },
};

static const std::string voicePath = "/voices/";
static const std::vector<std::string> voiceFiles = {
    "voice0000.mp3",
    "voice0001.mp3",
    "voice0002.mp3",
    "voice0003.mp3",
    "voice0004.mp3",
    "voice0005.mp3",
    "voice0006.mp3",
    "voice0007.mp3",
    "voice0008.mp3",
    "voice0009.mp3",
    "voice0011.mp3",
    "voice0012.mp3",
    "voice0013.mp3",
    "voice0014.mp3",
    "voice0015.mp3",
    "voice0016.mp3",
    "voice0017.mp3",
    "voice0018.mp3",
    "voice0019.mp3",
    "voice0021.mp3",
    "voice0022.mp3",
    "voice0023.mp3",
    "voice0024.mp3",
    "voice0025.mp3",
    "voice0026.mp3",
    "voice0027.mp3",
    "voice0028.mp3",
    "voice0029.mp3",
    "voice0031.mp3",
    "voice0032.mp3",
    "voice0033.mp3",
    "voice0034.mp3",
    "voice0035.mp3",
    "voice0036.mp3",
    "voice0037.mp3",
    "voice0038.mp3",
    "voice0039.mp3",
    "voice0040.mp3",
    "voice0099.mp3",
    "voice0100.mp3",
    "voice0101.mp3",
    "voice0102.mp3",
    "voice0103.mp3",
    "voice0104.mp3",
    "voice0105.mp3",
    "voice0106.mp3",
    "voice0107.mp3",
    "voice0108.mp3",
    "voice0109.mp3",
    "voice0110.mp3",
    "voice0111.mp3",
    "voice0112.mp3",
    "voice0113.mp3",
    "voice0201.mp3",
    "voice0202.mp3",
    "voice0203.mp3",
    "voice0204.mp3",
    "voice0205.mp3",
    "voice0206.mp3",
    "voice0207.mp3",
    "voice0208.mp3",
    "voice0209.mp3",
    "voice0210.mp3",
    "voice0211.mp3",
    "voice0212.mp3",
    "voice0213.mp3",
    "voice0214.mp3",
    "voice0215.mp3",
    "voice0216.mp3",
    "voice0217.mp3",
    "voice0218.mp3",
    "voice0219.mp3",
    "voice0220.mp3",
    "voice0221.mp3",
    "voice0222.mp3",
    "voice0223.mp3",
    "voice0224.mp3",
    "voice0225.mp3",
    "voice0226.mp3",
    "voice0227.mp3",
    "voice0228.mp3",
    "voice0229.mp3",
    "voice0230.mp3",
    "voice0231.mp3",
};

Main* Main::instance = NULL;

Scene* Main::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Main::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

void Main::httpRequest()
{
    auto httpRequest = new HttpRequest();
    
    httpRequest->setUrl("http://www.gaitameonline.com/rateaj/getrate");
    httpRequest->setRequestType(HttpRequest::Type::GET);
    httpRequest->setResponseCallback(this, httpresponse_selector(Main::callback));
    
    network::HttpClient::getInstance()->send(httpRequest);
}

void Main::callback(HttpClient* sender, HttpResponse* response)
{
    std::vector<char>* data = response->getResponseData();
    std::string result(data->begin(), data->end());
//    CCLOG(result.c_str());

    Json* json = Json_create(result.c_str());
    if(json != NULL) {
        Json* quotes = Json_getItem(json, "quotes");
        for(Json* element = quotes->child; element != NULL; element = element->next) {
            std::string pair = Json_getString(element, "currencyPairCode", NULL);
            Code2ISOMap::const_iterator src = c2is.find(pair.substr(0, 3));
            Code2ISOMap::const_iterator dst = c2is.find(pair.substr(3, 3));

            if(src != c2is.end() && dst != c2is.end()) {
                ISO4217 srcCode = src->second;
                ISO4217 dstCode = dst->second;
                const char* open = Json_getString(element, "open", "0");
                const char* high = Json_getString(element, "high", "0");
                const char* low = Json_getString(element, "low", "0");
                const char* ask = Json_getString(element, "ask", "0");
                const char* bid = Json_getString(element, "bid", "0");
                
                RateData rateData = {
                    srcCode,
                    dstCode,
                    std::strtof(open, NULL),
                    std::strtof(high, NULL),
                    std::strtof(low, NULL),
                    std::strtof(ask, NULL),
                    std::strtof(bid, NULL),
                };

                rates[srcCode][dstCode] = rateData;

                float swap = rateData.sale;
                rateData.sale = 1 / rateData.buy;
                rateData.buy = 1 / swap;

                rates[dstCode][srcCode] = rateData;
            }
        }
        Json_dispose(json);
    }
    
    refreshItems();
}

void Main::refreshItems() {

    for(std::vector<Item*>::iterator itr = items.begin(); itr != items.end(); ++itr) {
        (*itr)->refresh(rates[baseISO], baseValue);
    }    
}

// on "init" you need to initialize your instance
bool Main::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }

    instance = this;
    state = View;
    fromStartSec = 0;
    EventDispatcher* eventDispatcher = Director::getInstance()->getEventDispatcher();
    touchedItem = NULL;
    touchedCalcButton = NULL;

    calcValue = 0;
    calcIntegerValue = 0;
    calcDecimalValue = 0;
    calcIntegerFigure = 0;
    calcDecimalFigure = 0;
    calcDecimalOn = false;
    calcType = CalcButton::None;

    CocosDenshion::SimpleAudioEngine* audioEngine = CocosDenshion::SimpleAudioEngine::getInstance();

    for(int i = 0; i < voiceFiles.size(); ++i) {
        audioEngine->preloadEffect((voicePath + voiceFiles[i]).c_str());
    }

    // タッチイベント
    auto elta = EventListenerTouchAllAtOnce::create();
    elta->onTouchesBegan = [](const Touches& touches, Event* event) {
        for(int i = 0; i < touches.size(); ++i) {
            Main::Get()->SetTouch(touches[i], TouchBegan);
        }
    };    
    elta->onTouchesMoved = [](const Touches& touches, Event* event) {
        for(int i = 0; i < touches.size(); ++i) {
            Main::Get()->SetTouch(touches[i], TouchMoved);
        }
    };
    elta->onTouchesEnded = [](const Touches& touches, Event* event) {
        for(int i = 0; i < touches.size(); ++i) {
            Main::Get()->SetTouch(touches[i], TouchEnded);
        }
    };
    elta->onTouchesCancelled = [](const Touches& touches, Event* event) {
        for(int i = 0; i < touches.size(); ++i) {
            Main::Get()->SetTouch(touches[i], TouchCancelled);
        }
    };
    eventDispatcher->addEventListenerWithSceneGraphPriority(elta, this);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();

    baseISO = USD;
    baseValue = 1;
    httpRequest();

    scheduleUpdate();

    // モック
    Sprite* mock = Sprite::create("mockup.jpg");
    mock->setPosition(visibleSize.width/2, visibleSize.height/2);
    addChild(mock);

    Sprite* wallPaper = Sprite::create("wallpaper.png");
    wallPaper->setPosition(visibleSize.width/2, visibleSize.height/2);
    addChild(wallPaper);

    // アイテム
    itemLayer = Layer::create();
    addChild(itemLayer);

    ISO4217 firstItems[] = {
        JPY,
        USD,
        EUR,
        CHF,
        GBP,
        ZAR,
        ISO4217_NUM
    };

    Point itemPosition = Point(visibleSize.width/2, visibleSize.height - 128);
    for(int i = 0; firstItems[i] != ISO4217_NUM; ++i) {
        const ISOInfo& isoInfo = isoInfoMap.find(firstItems[i])->second;
        Item* item = Item::create(&isoInfo);
        item->SetColor(i % 2 ? Color3B(131,16,59): Color3B(4,29,86));
        item->setPosition(itemPosition);
        itemLayer->addChild(item);
        items.push_back(item);
        itemPosition.y -= item->GetItemHeight();
    }


    // キャラ
    charaLayer = Layer::create();
    charaLayer->setPosition(0,-568);
    charaLayer->runAction(Sequence::create(
//                            DelayTime::create(30),
                            EaseIn::create(
                                MoveTo::create(0.5f, Point(0,0)), 3
                            ),
                            NULL));
    addChild(charaLayer);

    charaUnitSprite = Sprite::create("kc_01_default.png");
    charaUnitSprite->setPosition(520, 128);
    charaUnitSprite->setScale(0.75f);
    charaUnitSprite->setAnchorPoint(Point(0.5f,0));
    charaLayer->addChild(charaUnitSprite);

    charaBalloonSprite = Sprite::create("balloon.png");
    charaBalloonSprite->setPosition(464, 240);
    charaBalloonSprite->setAnchorPoint(Point(1,0.5f));
    charaBalloonSprite->setVisible(false);
    charaLayer->addChild(charaBalloonSprite);
    
    charaMessage = Label::createWithSystemFont("杉田さん\nひどいっすわー","Arial",40);
    charaMessage->setColor(Color3B::BLACK);
    charaMessage->setPosition(192, 73);
    charaMessage->setVisible(false);
    charaBalloonSprite->addChild(charaMessage);    

    charaSpeakSprite = Sprite::create("sound.png");
    charaSpeakSprite->setPosition(visibleSize.width/2, 400);
    charaLayer->addChild(charaSpeakSprite);


    // フッタ
    Sprite* footer = Sprite::create("footer.png");
    footer->setPosition(visibleSize.width/2, 0);
    footer->setAnchorPoint(Point(0.5f,0.0f));
    Rect footerRect = footer->getTextureRect();
    addChild(footer);

    spriteMenu = Sprite::create("menu.png");
    spriteMenu->setPosition(visibleSize.width/6, footerRect.size.height/2);
    footer->addChild(spriteMenu);

    spriteReload = Sprite::create("reload.png");
    spriteReload->setPosition(visibleSize.width/2, footerRect.size.height/2);
    footer->addChild(spriteReload);

    spriteSettings = Sprite::create("settings.png");
    spriteSettings->setPosition(visibleSize.width/6*5, footerRect.size.height/2);
    footer->addChild(spriteSettings);

    // 電卓
    calcLayer = Layer::create();
    calcLayer->setPosition(Point(visibleSize.width/2,-visibleSize.height/2));
    addChild(calcLayer);

    CalcButton* calcButton = NULL;
    calcBackSprite = Sprite::create("calc_back.png");
    calcLayer->addChild(calcBackSprite);
    
    calcBaseLabel = Label::createWithSystemFont("999,999,999","Arial",64);
    calcBaseLabel->setAnchorPoint(Point(1,0.5f));
    calcBaseLabel->setPosition(Point(640,80+160*6));
    calcBackSprite->addChild(calcBaseLabel);

    calcCalcLabel = Label::createWithSystemFont("999,999,999","Arial",96);
    calcCalcLabel->setAnchorPoint(Point(1,0.5f));
    calcCalcLabel->setPosition(Point(640,80+160*5));
    calcBackSprite->addChild(calcCalcLabel);

    calcOperateLabel = Label::createWithSystemFont("","Arial",96);
    calcOperateLabel->setAnchorPoint(Point(0,0.5f));
    calcOperateLabel->setPosition(Point(0,80+160*5));
    calcBackSprite->addChild(calcOperateLabel);

    for(int i = 0; calcDatas[i].type != CalcButton::None; ++i) {
        CalcButton* calcButton = CalcButton::create(&calcDatas[i]);
        calcButtons.push_back(calcButton);
        calcBackSprite->addChild(calcButton);
    }
/*
    // 追加
    addDisp = false;

    addLayer = LayerColor::create(Color4B::BLACK);
    addLayer->setOpacity(127);
    addLayer->changeWidthAndHeight(240,1136);
    addLayer->setPosition(-240,0);
    addChild(addLayer);

    addTag = Sprite::create("add_tag.png");
    addTag->setAnchorPoint(Point(0,0.5f));
    addTag->setPosition(0,1024);
    addLayer->addChild(addTag);
*/

    return true;
}

float repeatTime = 0;
void Main::update(float deltaTime) {
    fromStartSec += deltaTime;
    repeatTime += deltaTime;
    if(repeatTime > 5) {
        httpRequest();
    }    

    switch(state) {
    case View:
        UpdateStateView();
        break;
    case CalcOpen:
        UpdateStateCalcOpen();
        break;
    case Calc:
        UpdateStateCalc();
        break;
    case CalcClose:
        UpdateStateCalcClose();
        break;        
    }

    // TouchBeganはupdate後にTouchStationaryに移行する
    for(int i = 0; i < MaxTouchNum; ++i) {
        switch(touchInfos[i].type) {
        case TouchBegan:
            touchInfos[i].type = TouchStationary;
            break;
        case TouchEnded:
        case TouchCancelled:
            touchInfos[i].type = TouchNone;
            break;
        }
    }
}

void Main::UpdateStateView() {
    Size visibleSize = Director::getInstance()->getVisibleSize();
    switch(touchInfos[0].type) {
    case TouchNone:
        if(ENABLE_MOVE_ITEM) {
            Point inputVec = touchInfos[0].posEnded - touchInfos[0].posBegan;
            Point layerPos = itemLayer->getPosition();
            Point movedPos = itemLayerPosBegan;

            movedPos.y += inputVec.y;
            scrollVec = (movedPos - layerPos) * 0.5f;
            movedPos = layerPos + scrollVec;
            itemLayer->setPosition(movedPos);
        }
/*
        if(items.size() > 0) {
            float topHeight = itemLayer->getPosition().y + items[0]->getPosition().y;
            float topLimit = visibleSize.height - (itemOffset / 2);
            if(topHeight < topLimit)
                scrollVec.y += (topLimit - topHeight) * 0.1f;
        }
        itemLayer->setPosition(itemLayer->getPosition() + scrollVec * 0.5f);
        scrollVec -= scrollVec * 0.2f;
*/
        break;

    case TouchBegan:
        // アイテム
        if(Item* item = GetTouchedItem(touchInfos[0].posBegan - itemLayer->getPosition())) {
            itemLayerPosBegan = itemLayer->getPosition();
            touchedItem = item;
            itemMove = Item::Stationary;
        }
/*        // 追加ウインドウタグ
        else {   
            Point pos = touchInfos[0].posBegan;
            Point vec = pos - (addLayer->getPosition() + addTag->getPosition());
            Rect buttonRect = addTag->getTextureRect();
            if(vec.x > 0 && vec.x < buttonRect.size.width && fabs(vec.y) < buttonRect.size.height/2) {
                if(addDisp) {
                    addLayer->runAction(
                        EaseIn::create(
                            MoveTo::create(0.25f,Point(-240,0)),
                            3
                        )
                    );                    
                }
                else {
                    addLayer->runAction(
                        EaseIn::create(
                            MoveTo::create(0.25f,Point(0,0)),
                            3
                        )
                    );                    
                }
            }
        }
*/        break;
    case TouchMoved:
        if(ENABLE_MOVE_ITEM && touchedItem != NULL) {
            Point inputVec = touchInfos[0].posMoved - touchInfos[0].posBegan;
            Point layerPos = itemLayer->getPosition();
            Point movedPos = itemLayerPosBegan;
            switch(itemMove) {
            case Item::Stationary:
                if(inputVec.x < -32.f) {
                    itemMove = Item::Delete;
                }
                else if(fabs(inputVec.y) > 32.f) {
                    itemMove = Item::Scroll;
                }
                break;
            case Item::Delete:
                RemoveItem(touchedItem);
                touchedItem = NULL;
                break;
            case Item::Scroll:
                movedPos.y += inputVec.y;
                scrollVec = (movedPos - layerPos) * 0.5f;
                movedPos = layerPos + scrollVec;
                itemLayer->setPosition(movedPos);
                CCLOG("moved pos y %.2f", movedPos.y);
                break;
            }
        }
        break;
    case TouchEnded:
    case TouchCancelled:
        if(touchedItem != NULL) {
            switch(itemMove) {
            case Item::Stationary:
                {
                    ISO4217 code = touchedItem->GetISOInfo()->code;
                    if(baseISO != code) {
                        baseISO = code;
                        baseValue = touchedItem->GetSaleValue();
                        refreshItems();
                    }
                    else {
                        state = CalcOpen;
                        calcValue = baseValue;
                        calcIntegerValue = 0;
                        calcDecimalValue = 0;
                        calcIntegerFigure = 0;
                        calcDecimalFigure = 0;
                        calcDecimalOn = false;
                        calcNumberSet = false;
                        calcEqual = true;
                        calcType = CalcButton::None;
                        DispCalcValue(true);

                        calcLayer->runAction(
                            EaseIn::create(
                                MoveTo::create(0.25f,Point(visibleSize.width/2,visibleSize.height/2)),
                                3
                            )
                        );
                    }
                }
                break;
            }
            touchedItem = NULL;
        }
        else {
            UpdateMessage();
        }
        break;
    }    
}

void Main::UpdateStateCalcOpen() {
    ActionManager* actMan = calcLayer->getActionManager();
    if(actMan->getNumberOfRunningActionsInTarget(calcLayer) == 0)
        state = Calc;
}

void Main::UpdateStateCalc() {
    Size visibleSize = Director::getInstance()->getVisibleSize();
    CalcButton* nextCalcButton = NULL;
    switch(touchInfos[0].type) {
    case TouchBegan:
/*
        touchedCalcButton = GetTouchedCalcButton(touchInfos[0].posBegan);
        if(touchedCalcButton != NULL) {

        }
*/
        break;
    case TouchMoved:
        break;
    case TouchEnded:
    case TouchCancelled:
        nextCalcButton = GetTouchedCalcButton(touchInfos[0].posBegan);
        if(nextCalcButton != NULL) {
            if(nextCalcButton->GetType() != CalcButton::Num) {
                if(touchedCalcButton != NULL) {
                    if(touchedCalcButton->IsType(calcType))
                        touchedCalcButton->Unselect();
                }
                touchedCalcButton = nextCalcButton;
            }
            int number = nextCalcButton->GetNum();
            CalcButton::Type type = nextCalcButton->GetType();
            bool close = false;
            bool equal = false;
            switch(type) {
            case CalcButton::Decide:
                OperateCalcValue();
                baseValue = calcValue;
                close = true;
                equal = true;
                break;
            case CalcButton::Cancel:
                calcValue = baseValue;
                close = true;
                equal = true;
                break;
            case CalcButton::Num:
                if(!calcNumberSet) {
                    calcNumberSet = true;
                    ResetInput();

                    if(calcEqual) {
                        calcType = CalcButton::None;
                        calcEqual = false;
                    }
                }
                if(calcDecimalOn) {
                    calcDecimalValue = MIN(calcDecimalValue * 10 + number, 999999);
                    calcDecimalFigure = MIN(calcDecimalFigure + 1, 6);
                }
                else {
                    if(calcIntegerValue > 0 || number > 0) {
                        calcIntegerValue = MIN(calcIntegerValue * 10 + number, 999999999);
                        calcIntegerFigure = MIN(calcIntegerFigure + 1, 9);
                    }
                }
                break;
            case CalcButton::Clear:
                if(calcIntegerFigure == 0 && calcIntegerValue == 0
                && calcDecimalFigure == 0 && calcDecimalValue == 0)
                {
                    calcValue = 0;
                    calcType = CalcButton::None;
                }
                else {
                    ResetInput();
                    calcNumberSet = false;                    
                }
                break;
            case CalcButton::Equal:
                OperateCalcValue(equal = true);
                break;
            case CalcButton::Delete:
                if(!calcNumberSet) {
                    calcNumberSet = true;
                    ResetInput();
                }
                if(calcDecimalOn) {
                    if(calcDecimalFigure > 0) {
                        calcDecimalValue /= 10;
                        calcDecimalFigure--;
                    }
                }
                else {
                    if(calcIntegerFigure > 0) {
                        calcIntegerValue /= 10;
                        calcIntegerFigure--;
                    }
                }
                break;
            case CalcButton::Decimal:
                if(!calcNumberSet) {
                    calcNumberSet = true;
                    ResetInput();
                }
                calcDecimalOn = true;
                break;
            // 演算子ボタン
            default:
                OperateCalcValue();
                calcType = type;
                nextCalcButton->Select();
                equal = true;
                break;
            }

            if(close) {
                calcLayer->runAction(
                    EaseIn::create(
                        MoveTo::create(0.25f,Point(visibleSize.width/2,-visibleSize.height/2)),
                        3
                    )
                );
                state = CalcClose;                
            }
            DispCalcValue(equal);
        }
        break;
    }
}

void Main::UpdateStateCalcClose() {
    ActionManager* actMan = calcLayer->getActionManager();
    if(actMan->getNumberOfRunningActionsInTarget(calcLayer) == 0)
        state = View;
}

// 電卓の値を表示する
void Main::DispCalcValue(bool equal) {

    char calcBuffer[64];
    float mod;
    if(modff(calcValue, &mod) > 0)
        sprintf(calcBuffer, "%f", calcValue);
    else sprintf(calcBuffer, "%.0f", calcValue);
    calcBaseLabel->setString(calcBuffer);

    if(equal) {
        calcCalcLabel->setString(calcBuffer);
        calcOperateLabel->setString("");
    }
    else {
        char integerBuffer[64];
        sprintf(integerBuffer, "%d", calcIntegerValue);
        std::string buffer = integerBuffer;
        if(calcDecimalOn) {
            if(calcDecimalFigure > 0) {
                char decimalFormat[64];
                sprintf(decimalFormat, ".%%0%dd", calcDecimalFigure);
                char decimalBuffer[64];
                sprintf(decimalBuffer, decimalFormat, calcDecimalValue);
                buffer += decimalBuffer;    
            }
            else {
                buffer += ".";
            }
        }
        calcCalcLabel->setString(buffer.c_str());

        switch(calcType) {
        case CalcButton::Add:
            calcOperateLabel->setString("+");
            break;
        case CalcButton::Sub:
            calcOperateLabel->setString("−");
            break;
        case CalcButton::Mul:
            calcOperateLabel->setString("×");
            break;
        case CalcButton::Div:
            calcOperateLabel->setString("÷");
            break;
        default:
            calcOperateLabel->setString("");
            break;
        }    
    }
}

// 電卓に入力した値を浮動小数で返す
float Main::CalcInputValue() {
    return calcIntegerValue + calcDecimalValue * pow(0.1f, calcDecimalFigure);
}

// 演算する
void Main::OperateCalcValue(bool equal) {
    if(calcNumberSet || equal) {
        float inputValue = CalcInputValue();
        switch(calcType) {
        case CalcButton::Add:
            calcValue += inputValue;
            break;
        case CalcButton::Sub:
            calcValue -= inputValue;
            if(calcValue < 0)
                calcValue = 0;
            break;
        case CalcButton::Mul:
            calcValue *= inputValue;
            break;
        case CalcButton::Div:
            if(calcIntegerValue != 0 || calcDecimalValue != 0)
                calcValue /= inputValue;
            break;
        default:
            calcValue = inputValue;
            break;
        }
    }
    calcEqual = equal;
    calcNumberSet = false;
}

void Main::ResetInput() {
    calcDecimalValue = 
    calcIntegerValue = 
    calcDecimalFigure =
    calcIntegerFigure = 0;
    calcDecimalOn = false;
}

void Main::RemoveItem(Item* item) {

    bool isRemoved = false;
    Point sortPos = item->getPosition();
    for(int i = 0; i < items.size(); ++i) {
        if(isRemoved) {
            Point pos = sortPos;
            sortPos = items[i]->getPosition();
            items[i]->setPosition(pos);
        }
        else if(item == items[i]) {
            isRemoved = true;
        }
    }
    item->Remove();
    items.erase(std::find(items.begin(), items.end(), item));
}

// タッチしたアイテムを取得する
Item* Main::GetTouchedItem(Point pos) {
    for(int i = 0; i < items.size(); ++i)
        if(items[i]->IsTouched(pos))
            return items[i];
    return NULL;
}

// タッチした電卓ボタンを取得する
CalcButton* Main::GetTouchedCalcButton(Point pos) {
    for(int i = 0; i < calcButtons.size(); ++i)
        if(calcButtons[i]->IsTouched(pos))
            return calcButtons[i];
    return NULL;
}

void Main::SetTouch(Touch* touch, TouchType type) {
    TouchInfo& touchInfo = touchInfos[touch->getID()];
    CCLOG("touched type %d", type);
    switch(type) {
    case TouchBegan:
        touchInfo.secBegan = fromStartSec;  
        touchInfo.posBegan = touch->getLocation();
        break;
    case TouchMoved:
        touchInfo.posMoved = touch->getLocation();
        break;
    case TouchEnded:
    case TouchCancelled:
        touchInfo.posEnded = touch->getLocation();
        break;
    }
    touchInfo.type = type;
}

void Main::UpdateMessage() {
    int message = (int)(100 * messageMotions.size() * CCRANDOM_0_1()) / 100;
    
    CocosDenshion::SimpleAudioEngine* audioEngine = CocosDenshion::SimpleAudioEngine::getInstance();
    int voice = (int)(100 * voiceFiles.size() * CCRANDOM_0_1()) / 100;
    audioEngine->playEffect((voiceFiles[voice]).c_str());

    const MessageMotion& messageMotion = messageMotions[message];
    charaMessage->setString(messageMotion.message.c_str());
    charaMessage->setVisible(true);
    charaBalloonSprite->setVisible(true);

    const std::string& sprite = motionSpriteMap.find(messageMotion.motion)->second;
//    charaUnitSprite->setTexture(sprite.c_str());

    Texture2D *tex = TextureCache::sharedTextureCache()->addImage(sprite.c_str());
    charaUnitSprite->setTexture(tex);
    Size contentSize = tex->getContentSize();
    charaUnitSprite->setTextureRect(CCRectMake(0, 0, contentSize.width, contentSize.height));




}

bool Item::init(const ISOInfo* isoInfo) {
    Node::init();

    // 
    spriteFrame = Sprite::create("flatitem.png");
    addChild(spriteFrame);
    Rect frameRect = spriteFrame->getTextureRect();
    itemHeight = frameRect.size.height;
/*
    // フラグ
    spriteFlag = Sprite::create(isoInfo->flag.c_str());
    spriteFlag->setPosition(Point(24, frameRect.size.height / 2));
    spriteFlag->setAnchorPoint(Point(0,0.5f));
    spriteFlag->setScale(0.4f);
    spriteFrame->addChild(spriteFlag);
*/
    // 名前
    labelCountry = Label::createWithSystemFont(isoInfo->country.c_str(), "Arial", 32);
    labelCountry->setPosition(Point(48, frameRect.size.height / 2));
    labelCountry->setAnchorPoint(Point(0,0.5f));
    spriteFrame->addChild(labelCountry);

    // 数値
    labelValue = Label::createWithSystemFont(isoInfo->unit.c_str(), "Arial", 32);
    labelValue->setPosition(Point(frameRect.size.width - 48, frameRect.size.height / 2));
    labelValue->setAnchorPoint(Point(1,0.5f));
    spriteFrame->addChild(labelValue);

    this->isoInfo = isoInfo;
    return true;
}

void Item::SetColor(Color3B color) {
    spriteFrame->setColor(color);
}

void Item::refresh(const std::map<ISO4217, RateData>& rates, float value) {
    char valueBuffer[64];
    if(rates.find(isoInfo->code) != rates.end()) {
        const RateData& rateData = rates.find(isoInfo->code)->second;
        saleValue = value * rateData.sale;
        sprintf(valueBuffer, "%.1f %s", saleValue, isoInfo->unit.c_str());
        labelCountry->setColor(Color3B::WHITE);
        labelValue->setColor(Color3B::WHITE);
    }
    else {
        saleValue = value;
        sprintf(valueBuffer, "%.1f %s", value, isoInfo->unit.c_str());        
        labelCountry->setColor(Color3B::YELLOW);
        labelValue->setColor(Color3B::YELLOW);
    }
    labelValue->setString(valueBuffer);
}

void Item::Remove() {
    spriteFrame->getParent()->removeChild(spriteFrame, true);
}

bool Item::IsTouched(Point pos) {
    Point vec = pos - _position;
    return (fabs(vec.x) < 320 && fabs(vec.y) < itemOffset/2);
}

bool CalcButton::init(
    const Data* data
)
{
    Node::init();

    buttonSprite = Sprite::create(data->sprite);
    buttonSprite->setColor(data->baseColor);
    addChild(buttonSprite);
    
    Rect buttonRect = buttonSprite->getTextureRect();
    titleLabel = Label::createWithSystemFont(data->title.c_str(), "Arial", 48);
    titleLabel->setPosition(buttonRect.size.width/2,buttonRect.size.height/2);
    buttonSprite->addChild(titleLabel);

    this->setPosition(data->position);
    this->data = data;
    return true;
}

bool CalcButton::IsTouched(Point pos) {
    Point vec = pos - (_position + buttonSprite->getPosition());
    Rect buttonRect = buttonSprite->getTextureRect();
    return (fabs(vec.x) < buttonRect.size.width/2 && fabs(vec.y) < buttonRect.size.height/2);
}
