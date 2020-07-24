/*
... iss Crew
... Made By Mukho
... 2020-07-23 TUE
... Kakaotalk Bot
*/

// Utils.getWeather : Copyright (C) 2020  Dark Tornado
Utils.getWeather = function(pos) {
    try {
        var data = org.jsoup.Jsoup.connect("https://m.search.naver.com/search.naver?query=" + pos.replace(/ /g, "+") + "+날씨").get();
        data = data.select("div.status_wrap");
        var temp = data.select("strong").get(0).text();
        temp = temp.replace("현재 온도", "온도 : ").replace("°", "℃");
        var hum = data.select("li.type_humidity").select("span").get(0).text();
        var state = data.select("div.weather_main").get(0).text();
        var dust = data.select("li.sign1").get(0);
        dust = dust.select("span.figure_text").text() + " (" + dust.select("span.figure_result").text() + ")";
        var result = "상태 : " + state + "\n" + temp + "\n습도 : " + hum + "%\n미세먼지 : " + dust;
        return result;
    } catch (e) {
        Log.error("날씨 정보 불러오기 실패\n" + e);
        return null;
    }
};

// 날짜 형식 변경 yyyy-MM-dd dddd
function getFormatDate(date)
{
    switch(date.getDay())
    {
        case 1:
            day = "월요일";
            break;
        case 2:
            day = "화요일";
            break;
        case 3:
            day = "수요일";
            break;
        case 4:
            day = "목요일";
            break;
        case 5:
            day = "금요일";
            break;
        case 6:
            day = "토요일";
            break;
        case 7:
            day = "일요일";
            break;
    }
    var today = date.getFullYear() + "년 " + (date.getMonth()) + "월 " + date.getDate() + "일 " + day;
    return today;
}

function response(room, msg, sender, isGroupChat, replier, ImageDB)
{    
    if(msg == "!명령어")
    {
        var help = "!주사위\n!날짜\n!전역일\n디데이\n실검\n전국날씨\n'지역' 날씨";
        replier.reply(help);
    }

    if(msg == "!주사위")
    {
        var dice = Math.floor(Math.random()*6)+1;
        replier.reply(dice);
    }

    if(msg == "!날짜")
    {
        var date = new Date();
        date = new Date(date.getFullYear(), date.getMonth()+1, date.getDate());
        today = getFormatDate(date);
        replier.reply(today);
    }

    if(msg == "!전역일")
    { 
        var date= new Date();
        startDate = new Date(2019, 11, 18); // 입대일 날짜
        endDate = new Date(2021, 06, 03); // 전역일 날짜
        today = new Date(date.getFullYear(), date.getMonth()+1, date.getDate()); // 오늘 날짜
        between = endDate - startDate; // 총 복무일(ms) 계산
        var total = between / (1000*3600*24); // 총 복무일 계산
        var remaining = (endDate - today) / (1000*3600*24) ; // 남은 복무일 계산
        var current = (today - startDate) / (1000*3600*24); // 현재 복무일 계산
        var percent = current / total*100; // 복무율(%) 계산

        var startDate_ = getFormatDate(startDate);
        var endDate_ = getFormatDate(endDate);

        replier.reply("묵호의" + 
        "\n입대일 : " + startDate_ +
        "\n전역일 : " + endDate_ +
        "\n총 복무일 : " + total + 
        "일\n현재 복무일 : " + current + 
        "일\n남은 복무일 : " + remaining + 
        "일\n복무율 : " + percent.toFixed(1) + "%");
    }

    if(msg == "!디데이")
    { 
        var date= new Date();
        var loveDate = new Date(2011, 11, 07); // 기준일
        today = new Date(date.getFullYear(), date.getMonth()+1, date.getDate()); // 오늘 날짜
        dday = today - loveDate; // 총 일수(ms) 계산
        var total = dday / (1000*3600*24); // 디데이 계산

        var loveDate_ = getFormatDate(loveDate);

        replier.reply("기준일 : " + loveDate_ + 
        "\nD-day : D+" + (total-1) ); // D-Day를 사용 중이므로 총 일수에서 -1일을 하면 디데이.
    }

    if (msg=="!실검")
    {
        var data=org.jsoup.Jsoup.connect("https://m.search.naver.com/search.naver?query=실시간%20검색어").get().select("span.tit")+"";
        data = data.replace(/<[^>]+>/g,"");
        data = data.split("\n");
        var result = "";
        for(var n =0; n<20; n++)
        {
            result += (n+1) + "위: " + data[n] + "\n";
        }
        replier.reply("[네이버 실시간 검색어 순위]\n\n" + result.trim());
    }

    if (msg == "!전국날씨")
    {
        var data1 = Utils.getWebText("https://m.search.naver.com/search.naver?query=날씨");
        var data2 = data1.split("전국날씨</strong>");
        var data3 = data2[1].split("단위 ℃");
        var data4 = data3[0].replace(/(<([^>]+)>)/g, "");
        data4 = data4.trim();
        data4 = ' ' + data4;
        data4 = data4.replace(/  /g, "\n");
        data4 = data4.replace(/도씨/g, "℃");
        data4 = data4.replace(/ /g, " ");

        replier.reply("[현재 날씨]\n" + data4);
    }

    // ex) 묵호 날씨 / 동해시 날씨 / 서울특별시 동대문구 회기동 / 회기동 날씨 / 경기도 영통구 날씨
    if (msg.split(" ")[0][0] == "!" && msg.indexOf('날씨') != -1 && msg != "!전국날씨")
    {
        var idx = msg.indexOf('날씨');
        var data = msg.slice(1, idx-1);
        var result = Utils.getWeather(data);
        if (result == null) replier.reply("날씨 정보 불러오기 실패");
        else replier.reply("[" + data + " 날씨 정보]\n" + result);
    }
}