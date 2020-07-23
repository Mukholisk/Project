function response(room, msg, sender, isGroupChat, replier, ImageDB)
{    
    if(msg == "!명령어")
    {
        var help = "!주사위\n!날짜\n!전역일";
        replier.reply(help);
    }

    if(msg == "!주사위")
    {
        var dice = Math.floor(Math.random()*6)+1;
        replier.reply(dice);
    }

    if(msg == "!날짜")
    {
        var date = new Date
        var day;
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
        var today = date.getFullYear() + "년 " + (date.getMonth()+1) + "월 " + date.getDate() + "일 " + day;
        replier.reply(today);
    }

    if(msg == "!전역일")
    { 
        var date= new Date();
        startDate = new Date(2019, 11, 18); // 입대일 날짜
        endDate = new Date(2021, 06, 03); // 전역일 날짜
        today = new Date(date.getFullYear(), date.getMonth()+1, date.getDate()); //오늘 날짜
        between = endDate - startDate; // 총 복무일(ms) 계산
        var total = between / (1000*3600*24); // 총 복무일 계산
        var remaining = (endDate - today)/ (1000*3600*24) ; // 남은 복무일 계산
        var current = (today - startDate) / (1000*3600*24); // 현재 복무일 계산
        var percent = current / total*100; // 복무율(%) 계산

        replier.reply("총 복무일 : " + total + 
        "일\n현재 복무일 : " + current + 
        "일\n남은 복무일 : " + remaining + 
        "일\n복무율 : " + percent.toFixed(1) + "%");
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
        replier.reply("[네이버 실시간 검색어 순위]\n\n" + result.trim()); }

}
