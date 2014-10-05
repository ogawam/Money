#include "MainScene.h"
#include "spine/Json.h"

//using namespace extension;
using namespace cocos2d::network;

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
            rateData.sale = rateData.buy;
            rateData.buy = rateData.sale;

            rates[dstCode][srcCode] = rateData;
        }
        
    }
    Json_dispose(json);
    
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

    itemLayer = Layer::create();
    addChild(itemLayer);

    Point itemPosition = Point(visibleSize.width/2, visibleSize.height - 128);
    for(ISOInfoMap::const_iterator itr = isoInfoMap.begin(); itr != isoInfoMap.end(); ++itr) {
        Item* item = Item::create(&itr->second);
        item->setPosition(itemPosition);
        itemLayer->addChild(item);
        items.push_back(item);
        itemPosition.y -= 160;
    }

    calcLayer = Layer::create();
    calcLayer->setPosition(Point(visibleSize.width/2,-visibleSize.height/2));
    addChild(calcLayer);

    CalcButton* calcButton = NULL;
    calcBackSprite = Sprite::create("calc_back.png");
    calcLayer->addChild(calcBackSprite);
    calcButtons.push_back(CalcButton::create(CalcButton::Num, 0, Color3B::GRAY, "０", "calc160x160.png"));
    calcButtons.push_back(CalcButton::create(CalcButton::Num, 1, Color3B::GRAY, "１", "calc160x160.png"));
    calcButtons.push_back(CalcButton::create(CalcButton::Num, 2, Color3B::GRAY, "２", "calc160x160.png"));
    calcButtons.push_back(CalcButton::create(CalcButton::Num, 3, Color3B::GRAY, "３", "calc160x160.png"));
    calcButtons.push_back(CalcButton::create(CalcButton::Num, 4, Color3B::GRAY, "４", "calc160x160.png"));
    calcButtons.push_back(CalcButton::create(CalcButton::Num, 5, Color3B::GRAY, "５", "calc160x160.png"));
    calcButtons.push_back(CalcButton::create(CalcButton::Num, 6, Color3B::GRAY, "６", "calc160x160.png"));
    calcButtons.push_back(CalcButton::create(CalcButton::Num, 7, Color3B::GRAY, "７", "calc160x160.png"));
    calcButtons.push_back(CalcButton::create(CalcButton::Num, 8, Color3B::GRAY, "８", "calc160x160.png"));
    calcButtons.push_back(CalcButton::create(CalcButton::Num, 9, Color3B::GRAY, "９", "calc160x160.png"));
    for(int i = 0; i < calcButtons.size(); ++i) {
        calcButtons[i]->setPosition(Point(80+160*(i%4), 80+160*(i/4)));
        calcBackSprite->addChild(calcButtons[i]);
    }
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
    }

    // TouchBeganはupdate後にTouchStationaryに移行する
    for(int i = 0; i < MaxTouchNum; ++i) {
        if(touchInfos[i].type == TouchBegan)
            touchInfos[i].type = TouchStationary;
    }
}

void Main::UpdateStateView() {
    Size visibleSize = Director::getInstance()->getVisibleSize();
    switch(touchInfos[0].type) {
    case TouchBegan:
        if(Item* item = GetTouchedItem(touchInfos[0].posBegan - itemLayer->getPosition())) {
            itemLayerPosBegan = itemLayer->getPosition();
            touchedItem = item;
            itemMove = Item::Stationary;
        }
        break;
    case TouchMoved:
        if(touchedItem != NULL) {
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
                inputVec = movedPos - layerPos;
                movedPos = layerPos + inputVec * 0.5f;
                itemLayer->setPosition(movedPos);
                break;
            }
        }
        break;
    case TouchEnded:
    case TouchCancelled:
        if(touchedItem != NULL) {
            if(itemMove == Item::Stationary) {
                ISO4217 code = touchedItem->GetISOInfo()->code;
                if(baseISO != code) {
                    baseISO = code;
                }
                else {
                    state = CalcOpen;
/*
                    calcLayer->runAction(
                        EaseIn::create(
                            MoveTo::create(0.25f,Point(visibleSize.width/2,visibleSize.height/2)),
                            3
                        )
                    );
*/
                }
            }
            touchedItem = NULL;
        }
        break;
    }    
}

void Main::UpdateStateCalcOpen() {

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

bool Item::init(const ISOInfo* isoInfo) {
    Node::init();

    // 
    spriteFrame = Sprite::create("flatitem.png");
    addChild(spriteFrame);
    Rect frameRect = spriteFrame->getTextureRect();

    // フラグ
    spriteFlag = Sprite::create(isoInfo->flag.c_str());
    spriteFlag->setPosition(Point(24, frameRect.size.height / 2));
    spriteFlag->setAnchorPoint(Point(0,0.5f));
    spriteFlag->setScale(0.4f);
    spriteFrame->addChild(spriteFlag);

    // 名前
    labelCountry = LabelTTF::create(isoInfo->country.c_str(), "Arial", 24);
    labelCountry->setPosition(Point(160, frameRect.size.height / 4 * 3));
    labelCountry->setAnchorPoint(Point(0,0.5f));
    spriteFrame->addChild(labelCountry);

    // 数値
    labelValue = LabelTTF::create(isoInfo->unit.c_str(), "Arial", 48);
    labelValue->setPosition(Point(frameRect.size.width - 16, frameRect.size.height / 4));
    labelValue->setAnchorPoint(Point(1,0.5f));
    spriteFrame->addChild(labelValue);

    this->isoInfo = isoInfo;
    return true;
}

void Item::refresh(const std::map<ISO4217, RateData>& rates, float value) {
    char valueBuffer[64];
    if(rates.find(isoInfo->code) != rates.end()) {
        const RateData& rateData = rates.find(isoInfo->code)->second;
        sprintf(valueBuffer, "%.1f %s", value * rateData.sale, isoInfo->unit.c_str());
        labelCountry->setColor(Color3B::WHITE);
        labelValue->setColor(Color3B::WHITE);
    }
    else {
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
    if(fabs(vec.x) < 320 && fabs(vec.y) < 64) {
        CCLOG("touch %s", isoInfo->country.c_str());
        return true;
    }
    return false;
}

bool CalcButton::init(
    Type type, int number, Color3B baseColor, 
    std::string title, std::string sprite
)
{
    Node::init();

    buttonSprite = Sprite::create(sprite);
    buttonSprite->setColor(baseColor);
    addChild(buttonSprite);
    titleLabel = LabelTTF::create(title.c_str(), "Arial", 48);
    titleLabel->setPosition(Point(80,80));
    buttonSprite->addChild(titleLabel);

    this->type = type;
    this->number = number;
    this->baseColor = baseColor;    
    return true;
}
