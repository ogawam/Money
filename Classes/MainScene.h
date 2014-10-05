#ifndef __MAIN_SCENE_H__
#define __MAIN_SCENE_H__

#include "cocos2d.h"

#include "network/HttpClient.h"

USING_NS_CC;

enum ISO4217 {
    AED, // UAEディルハム    アラブ首長国連邦の旗 アラブ首長国連邦 
    AFN, // アフガニ    アフガニスタンの旗 アフガニスタン   
    ALL, // レク  アルバニアの旗 アルバニア   
    AMD, // ドラム アルメニアの旗 アルメニア   
    ANG, // アンティル・ギルダー  キュラソー島の旗 キュラソー、シント・マールテンの旗 シント・マールテン    
    AOA, // クワンザ    アンゴラの旗 アンゴラ 
    ARS, // アルゼンチン・ペソ   アルゼンチンの旗 アルゼンチン 
    AUD, // オーストラリア・ドル  オーストラリアの旗 オーストラリア   
    AWG, // アルバ・フロリン    アルバの旗 アルバ   
    AZN, // アゼルバイジャン・マナト    アゼルバイジャンの旗 アゼルバイジャン 
    BAM, // 兌換マルク   ボスニア・ヘルツェゴビナの旗 ボスニア・ヘルツェゴビナ 
    BBD, // バルバドス・ドル    バルバドスの旗 バルバドス   
    BDT, // タカ  バングラデシュの旗 バングラデシュ   
    BGN, // レフ  ブルガリアの旗 ブルガリア   1999年7月5日以降（以前はBGL）
    BHD, // バーレーン・ディナール バーレーンの旗 バーレーン   
    BIF, // ブルンジ・フラン    ブルンジの旗 ブルンジ 
    BMD, // バミューダ・ドル    バミューダ諸島の旗 バミューダ諸島   
    BND, // ブルネイ・ドル ブルネイの旗 ブルネイ 
    BOB, // ボリビアーノ  ボリビアの旗 ボリビア 
    BRL, // レアル ブラジルの旗 ブラジル 
    BSD, // バハマ・ドル  バハマの旗 バハマ   
    BTN, // ニュルタム   ブータンの旗 ブータン 
    BWP, // プラ  ボツワナの旗 ボツワナ 
    BYR, // ベラルーシ・ルーブル  ベラルーシの旗 ベラルーシ   
    BZD, // ベリーズ・ドル ベリーズの旗 ベリーズ 
    CAD, // カナダ・ドル  カナダの旗 カナダ   
    CDF, // コンゴ・フラン コンゴ民主共和国の旗 コンゴ民主共和国 
    CHF, // スイス・フラン スイスの旗 スイス   
    CLP, // チリ・ペソ   チリの旗 チリ 
    CNY, // 人民元 中華人民共和国の旗 中華人民共和国   
    COP, // コロンビア・ペソ    コロンビアの旗 コロンビア   
    CRC, // コスタリカ・コロン   コスタリカの旗 コスタリカ   
    CSD, // セルビア・ディナール  セルビアの旗 セルビア 
    CUC, // 兌換ペソ    キューバの旗 キューバ 
    CUP, // キューバ・ペソ キューバの旗 キューバ 
    CVE, // カーボベルデ・エスクード    カーボベルデの旗 カーボベルデ 
    CZK, // チェコ・コルナ チェコの旗 チェコ   
    DJF, // ジブチ・フラン ジブチの旗 ジブチ   
    DKK, // デンマーク・クローネ  デンマークの旗 デンマーク   
    DOP, // ドミニカ・ペソ ドミニカ共和国の旗 ドミニカ共和国   
    DZD, // アルジェリア・ディナール    アルジェリアの旗 アルジェリア 
    EGP, // エジプト・ポンド    エジプトの旗 エジプト 
    ERN, // ナクファ    エリトリアの旗 エリトリア   
    ETB, // ブル  エチオピアの旗 エチオピア   
    EUR, // ユーロ 欧州連合の旗 欧州連合 (EU)    2014年1月現在、EU28カ国中18カ国が採用
    FJD, // フィジー・ドル フィジーの旗 フィジー 
    FKP, // フォークランド諸島・ポンド   フォークランド諸島の旗 フォークランド諸島   
    GBP, // UKポンド   イギリスの旗 イギリス 
    GEL, // ラリ  グルジアの旗 グルジア 
    GGP, // ガーンジー・ポンド   ガーンジー島の旗 ガーンジー島 
    GHS, // セディ ガーナの旗 ガーナ   
    GIP, // ジブラルタル・ポンド  ジブラルタルの旗 ジブラルタル 
    GMD, // ダラシ ガンビアの旗 ガンビア 
    GNF, // ギニア・フラン ギニアの旗 ギニア   
    GTQ, // ケツァル    グアテマラの旗 グアテマラ   
    GYD, // ガイアナ・ドル ガイアナの旗 ガイアナ 
    HKD, // 香港ドル    香港の旗 香港 
    HNL, // レンピラ    ホンジュラスの旗 ホンジュラス 
    HRK, // クーナ クロアチアの旗 クロアチア   
    HTG, // グールド    ハイチの旗 ハイチ   
    HUF, // フォリント   ハンガリーの旗 ハンガリー   
    IDR, // ルピア インドネシアの旗 インドネシア 
    ILS, // 新シェケル   イスラエルの旗 イスラエル   
    INR, // インド・ルピー インドの旗 インド   
    IQD, // イラク・ディナール   イラクの旗 イラク   
    IRR, // イラン・リヤル イランの旗 イラン   
    ISK, // アイスランド・クローナ アイスランドの旗 アイスランド 
    JMD, // ジャマイカ・ドル    ジャマイカの旗 ジャマイカ   
    JOD, // ヨルダン・ディナール  ヨルダンの旗 ヨルダン 
    JPY, // 円   日本の旗 日本 
    KES, // ケニア・シリング    ケニアの旗 ケニア   
    KGS, // キルギス・ソム キルギスの旗 キルギス 
    KHR, // リエル カンボジアの旗 カンボジア   
    KMF, // コモロ・フラン コモロの旗 コモロ   
    KPW, // ウォン 朝鮮民主主義人民共和国の旗 朝鮮民主主義人民共和国   
    KRW, // ウォン 韓国の旗 大韓民国   
    KWD, // クウェート・ディナール クウェートの旗 クウェート   
    KYD, // ケイマン諸島・ドル   ケイマン諸島の旗 ケイマン諸島 
    KZT, // テンゲ カザフスタンの旗 カザフスタン 
    LAK, // キープ ラオスの旗 ラオス   
    LBP, // レバノン・ポンド    レバノンの旗 レバノン 
    LKR, // スリランカ・ルピー   スリランカの旗 スリランカ   
    LRD, // リベリア・ドル リベリアの旗 リベリア 
    LSL, // ロチ  レソトの旗 レソト   
    LTL, // リタス リトアニアの旗 リトアニア   
    LYD, // リビア・ディナール   リビアの旗 リビア   
    MAD, // モロッコ・ディルハム  モロッコの旗 モロッコ 
    MDL, // モルドバ・レウ モルドバの旗 モルドバ 
    MGA, // アリアリ    マダガスカルの旗 マダガスカル 
    MKD, // マケドニア・デナール  マケドニア共和国の旗 マケドニア共和国 
    MMK, // チャット    ミャンマーの旗 ミャンマー   
    MNT, // トゥグルグ   モンゴルの旗 モンゴル国    
    MOP, // パタカ マカオの旗 マカオ   
    MRO, // ウギア モーリタニアの旗 モーリタニア 
    MUR, // モーリシャス・ルピー  モーリシャスの旗 モーリシャス 
    MVR, // ルフィヤ    モルディブの旗 モルディブ   
    MWK, // マラウイ・クワチャ   マラウイの旗 マラウイ 
    MXN, // メキシコ・ペソ メキシコの旗 メキシコ 
    MYR, // リンギット   マレーシアの旗 マレーシア   
    MZN, // メティカル   モザンビークの旗 モザンビーク 
    NAD, // ナミビア・ドル ナミビアの旗 ナミビア 
    NGN, // ナイラ ナイジェリアの旗 ナイジェリア 
    NIO, // ニカラグア・コルドバ  ニカラグアの旗 ニカラグア   
    NOK, // ノルウェー・クローネ  ノルウェーの旗 ノルウェー   
    NPR, // ネパール・ルピー    ネパールの旗 ネパール 
    NZD, // ニュージーランド・ドル ニュージーランドの旗 ニュージーランド 
    OMR, // オマーン・リアル    オマーンの旗 オマーン 
    PAB, // バルボア    パナマの旗 パナマ   
    PEN, // ヌエボ・ソル  ペルーの旗 ペルー   
    PGK, // キナ  パプアニューギニアの旗 パプアニューギニア   
    PHP, // フィリピン・ペソ    フィリピンの旗 フィリピン   
    PKR, // パキスタン・ルピー   パキスタンの旗 パキスタン   
    PLN, // ズウォティ   ポーランドの旗 ポーランド   
    PYG, // グアラニー   パラグアイの旗 パラグアイ   
    QAR, // カタール・リヤル    カタールの旗 カタール 
    RON, // 新ルーマニア・レウ   ルーマニアの旗 ルーマニア   
    RUB, // ロシア・ルーブル    ロシアの旗 ロシア   
    RWF, // ルワンダ・フラン    ルワンダの旗 ルワンダ 
    SAR, // サウジアラビア・リヤル サウジアラビアの旗 サウジアラビア   
    SBD, // ソロモン諸島ドル    ソロモン諸島の旗 ソロモン諸島 
    SCR, // セーシェル・ルピー   セーシェルの旗 セーシェル   
    SDG, // スーダン・ポンド    スーダンの旗 スーダン 
    SEK, // スウェーデン・クローナ スウェーデンの旗 スウェーデン 
    SGD, // シンガポール・ドル   シンガポールの旗 シンガポール 
    SHP, // セントヘレナ・ポンド  セントヘレナの旗 セントヘレナ 
    SLL, // レオン シエラレオネの旗 シエラレオネ 
    SOS, // ソマリア・シリング   ソマリアの旗 ソマリア 
    SRD, // スリナム・ドル スリナムの旗 スリナム 2004年1月1日から使用
    SSP, // 南スーダン・ポンド   南スーダンの旗 南スーダン   
    STD, // ドブラ サントメ・プリンシペの旗 サントメ・プリンシペ 
    SVC, // サルバドール・コロン  エルサルバドルの旗 エルサルバドル   
    SYP, // シリア・ポンド シリアの旗 シリア   
    SZL, // リランゲニ   スワジランドの旗 スワジランド 
    THB, // バーツ タイ王国の旗 タイ   
    TJS, // ソモニ タジキスタンの旗 タジキスタン 
    TMT, // トルクメニスタン・マナト    トルクメニスタンの旗 トルクメニスタン 
    TND, // チュニジア・ディナール チュニジアの旗 チュニジア   
    TOP, // パアンガ    トンガの旗 トンガ   
    TRY, // 新トルコリラ  トルコの旗 トルコ   
    TTD, // トリニダード・トバゴ・ドル   トリニダード・トバゴの旗 トリニダード・トバゴ 
    TWD, // ニュー台湾ドル 中華民国の旗 中華民国 
    TZS, // タンザニア・シリング  タンザニアの旗 タンザニア   
    UAH, // フリヴニャ   ウクライナの旗 ウクライナ   
    UGX, // ウガンダ・シリング   ウガンダの旗 ウガンダ 
    USD, // アメリカ合衆国ドル   アメリカ合衆国の旗 アメリカ合衆国   
    UYU, // ウルグアイ・ペソ    ウルグアイの旗 ウルグアイ   
    UZS, // スム  ウズベキスタンの旗 ウズベキスタン   
    VEF, // ボリバル    ベネズエラの旗 ベネズエラ   
    VND, // ドン  ベトナムの旗 ベトナム 
    VUV, // バツ  バヌアツの旗 バヌアツ 
    WST, // タラ  サモアの旗 サモア   
    XAF, // CFAフラン  中部アフリカ諸国    中部アフリカ諸国銀行 (BEAC) が発行
    XAG, // 銀   (なし)    
    XAU, // 金   (なし)    
    XCD, // 東カリブ・ドル カリブ海諸国  
    XDR, // 特別引出権   (なし)    国際通貨基金
    XOF, // CFAフラン  西アフリカ諸国 西アフリカ諸国中央銀行 (BCEAO) が発行
    XPD, // パラジウム   (なし)    
    XPF, // CFPフラン  フランス海外領土（太平洋）   
    XPT, // 白金  (なし)    
    XTS, // テスト用コード (なし)    
    XXX, // 通貨なし    (なし)    
    YER, // イエメン・リアル    イエメンの旗 イエメン 
    ZAR, // ランド 南アフリカ共和国の旗 南アフリカ共和国 
    ZMK, // ザンビア・クワチャ   ザンビアの旗 ザンビア 
    ZWD, // ジンバブエ・ドル    ジンバブエの旗 ジンバブエ   
    ISO4217_NUM
};

typedef const std::pair<std::string, ISO4217> Code2ISO;
typedef const std::map<std::string, ISO4217> Code2ISOMap;

struct ISOInfo {
	ISO4217 code;
    std::string unit;
    std::string country;
    std::string flag;
};

typedef const std::pair<ISO4217, ISOInfo> ISOInfoPair;
typedef const std::map<ISO4217, ISOInfo> ISOInfoMap;

struct RateData {
    ISO4217 srcCode;
    ISO4217 dstCode;
    float open;
    float high;
    float low;
    float sale;
    float buy;
};

class Item : public Node
{
public:
	enum Move {
		Stationary,
		Delete,
		Scroll
	};

	static Item* create(const ISOInfo* isoInfo) {
		Item * ret = new Item();
	    if (ret && ret->init(isoInfo))
	    {
	        ret->autorelease();
	    }
	    else
	    {
	        CC_SAFE_DELETE(ret);
	    }
		return ret;
    }
    void refresh(const std::map<ISO4217, RateData>& rates, float value);
    bool IsTouched(Point pos);
    void Remove();
    const ISOInfo* GetISOInfo() { return isoInfo; }
protected:
    virtual bool init(const ISOInfo* isoInfo);  
private:
	const ISOInfo* isoInfo;
	Sprite* spriteFrame;
	Sprite* spriteFlag;
	Label* labelCountry;
	Label* labelValue;
};

class CalcButton : public Node
{
public:
    enum Type {
        Num,
        Add,
        Sub,
        Mul,
        Div,
        Clear,
        Equal,
        Decimal,
    };
    static CalcButton* create(
        Type type, int number, Color3B baseColor, 
        std::string title, std::string sprite
    ) {
        CalcButton * ret = new CalcButton();
        if (ret && ret->init(type, number, baseColor, title, sprite))
        {
            ret->autorelease();
        }
        else
        {
            CC_SAFE_DELETE(ret);
        }
        return ret;
    }
protected:
    virtual bool init(
        Type type, int number, Color3B baseColor, 
        std::string title, std::string sprite
    );    
private:
    Sprite* buttonSprite;
    Label* titleLabel;

    Type type;
    int number;
    Color3B baseColor;
};

enum TouchType {
	TouchBegan,
	TouchStationary,
	TouchMoved,
	TouchEnded,
	TouchCancelled,
};

struct TouchInfo {
	float secBegan;
	Point posBegan;
	Point posMoved;
	Point posEnded;
	TouchType type;
	TouchInfo()
	: secBegan(0)
	, type(TouchEnded) {}
};

const int MaxTouchNum = 5;

typedef std::vector<Touch*> Touches;
class Main : public Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static Scene* createScene();
    static Main* Get() { return instance; }
    void SetTouch(Touch* touch, TouchType type);

    // implement the "static create()" method manually
    CREATE_FUNC(Main);

protected:	
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    virtual void update(float deltaTime);

	void httpRequest();
	void refreshItems();

	virtual void callback(network::HttpClient* sender, network::HttpResponse* response);
    
private:
	Item* GetTouchedItem(Point pos);
	void RemoveItem(Item* item);

    void UpdateStateView();
    void UpdateStateCalcOpen();

	static Main* instance;
	std::map<ISO4217, std::map<ISO4217, RateData> > rates;

	TouchInfo touchInfos[MaxTouchNum];
	float fromStartSec;

    enum State {
        View,
        CalcOpen,
        Calc,
        CalcClose,
    } state;

    // 為替
	Layer* itemLayer;
	Point itemLayerPosBegan;
	std::vector<Item*> items;

    // 電卓
    Layer* calcLayer;
    Sprite* calcBackSprite;
    Label* calcInfoLabel;
    std::vector<CalcButton*> calcButtons;

	Item* touchedItem;
	Item::Move itemMove;
	ISO4217 baseISO;
	float baseValue;
};

#endif // __MAIN_SCENE_H__
