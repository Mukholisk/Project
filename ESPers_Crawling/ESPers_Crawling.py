# ... iss Crew
# ... Made By Mukho
# ... 2022-03-22 MON
# ... Last Update : 2022-03-23 WEN
# op.gg 서버 등록 id 기준으로 검색하기 때문에 null값이 입력될 가능성이 존재한다.
# ID 누락의 경우 직접 csv file에서 수정해줘야한다.
# csv 파일에 이름과 아이디만 붙여넣고 잘 가공하면 된다.
# 좀 오래걸린다.(2분) 느리면 직접 해라.

#-*-coding: utf-8 -*-
import bs4
import urllib.parse as parse
import urllib.request as request
import csv
import os

class Application:
    def __init__(self):
        #data = [ [name, ID, tier, pre_tier], ..., [] ]
        self.data = []
              
    def getCommend(self):
        print("-------------------------------")
        print("---  크롤링 프로그램입니다  ---")
        print("-- 1.   추가                 --")
        print("-- 2.   삭제                 --")
        print("-- 3. 정보갱신               --")
        print("-- 4.   출력                 --")
        print("-- 5.   저장                 --")
        print("-- 6. 불러오기               --")
        print("-- 0.   종료                 --")
        print("-------------------------------")
        cmd = int(input("-- 기능을 선택하세요 : "))

        return cmd

    def run(self):
        while(1):
            num = self.getCommend()

            if num == 1:
                self.add()
            elif num == 2:
                self.remove()
            elif num == 3:
                self.crawling()
            elif num == 4:
                self.show()
            elif num == 5:
                self.save()
            elif num == 6:
                self.load()
            elif num == 0:
                break
            else:
                print("★ 잘못된 선택입니다.")

    # 중복된 값을 거름, 정렬..?
    def add(self):
        os.system("cls")
        print("---          추 가          ---")
        name = input("이름을 입력하세요 : ")
        id = input("ID를 입력하세요 : ")
        isSame = False

        for i in range(len(self.data)):
            if str(self.data[i][1]).replace(' ', '') != id.replace(' ', ''):
                continue
            else: # 중복인 데이터를 입력받았을 경우
                isSame = True
                break

        if not isSame:
            temp = [name, id, '', ''] # 사용자로부터 이름과 id만 입력받고, 나머지 값은 ''로 초기화
            self.data.append(temp)
            print("추가되었습니다.")
        else:
            print("입력한 id 값과 중복된 값이 존재합니다.")

    def remove(self):
        os.system("cls")
        isRemove = False
        print("---          삭 제          ---")
        id = input("제거할 ID를 입력하세요 : ")
        for i in range(0, len(self.data)):
            if id == self.data[i][1]:
                del self.data[i]
                isRemove = True
                break
        
        if isRemove:
            print("삭제되었습니다.")
        else:
            print("삭제하지 못했습니다.")
        
    def crawling(self):
        i = 0
        if len(self.data) == 0:
            print("data가 없습니다.")
        else:
            while i < len(self.data):     
                # 파일(dataFile.csv)에서 불러온 목록 중 아이디가 공백('')이 아닌가? - 210326에 버그 찾음
                if(self.data[i][1] == ''):
                    print(self.data[i][0]+"의 id 값이 없어 제거합니다.")
                    del self.data[i]
                    continue
                # url로 크롤링
                url = "https://www.op.gg/summoner/userName=" + parse.quote(self.data[i][1])
                req = request.urlopen(url)
                soup = bs4.BeautifulSoup(req, 'html.parser')
                isError = False # 잘못된 아이디인가

                # op.gg에 등록되지 않은 아이디인가?
                if str(type(soup.find('h2'))) == "<class 'NoneType'>":
                    #if str(type(soup.find('div', 'ChampionImage'))) == "<class 'NoneType'>": # 등록은 되어있지만 전적이 없는 아이디인가?
                        #isError = True
                    #else:
                        #isError = False
                    print('',end='')
                elif soup.find('h2').text == "This summoner is not registered at OP.GG. Please check spelling.": # 등록이 안되어 있는가?
                    isError = True
                
                # 잘못된 아이디
                if isError:
                    print("op.gg에 등록되지 않은 소환사입니다. '" + self.data[i][1] + "' id의 데이터를 삭제합니다.")
                    del self.data[i]
                    if i != 0:
                        i -= 1
                else:
                    user_info = list(str(soup.find_all('meta')[-2])[15:-29].split(' / '))
                    if len(user_info) > 3:
                        temp_most = list(user_info[3].split(', '))
                        temp_most_list = []
                        for m in temp_most:
                            temp = list(m.split())
                            temp_most_list.append(temp[0])
                        user_info[3] = temp_most_list

                    tier_lp = soup.find("div", "css-kff9ir e1y28yym2")

                    print(tier_lp)
                    # 아이디, 현재 시즌 티어
                    self.data[i][1] = user_info[0]
                    self.data[i][2] = "Unranked" if user_info[1].find('Lv') == 0 else " ".join(list(user_info[1].split())[:2])
                    
                    # 직접 정규화
                    pre_season_html = str(soup.find("div", "css-nvyacf e1y28yym3").find_all("li"))[1:-1]
                    while(True):
                        if '<div class="" style="position:relative">' in pre_season_html:
                            s = pre_season_html.find('<div class="" style="position:relative">')
                            pre_season_html = pre_season_html[:s] + pre_season_html[s+40:]
                        else:
                            break
                    while(True):
                        if '<!-- -->' in pre_season_html:
                            s = pre_season_html.find('<!-- -->')
                            pre_season_html = pre_season_html[:s] + pre_season_html[s+8:]
                        else:
                            break
                    while(True):
                        if '<b>' in pre_season_html:
                            s = pre_season_html.find('<b>')
                            pre_season_html = pre_season_html[:s] + pre_season_html[s+3:]
                        else:
                            break
                    while(True):
                        if '</b>' in pre_season_html:
                            s = pre_season_html.find('</b>')
                            pre_season_html = pre_season_html[:s] + pre_season_html[s+4:]
                        else:
                            break
                    while(True):
                        if '<li>' in pre_season_html:
                            s = pre_season_html.find('<li>')
                            pre_season_html = pre_season_html[:s] + pre_season_html[s+4:]
                        else:
                            break
                    while(True):
                        if '</li>' in pre_season_html:
                            s = pre_season_html.find('</li>')
                            pre_season_html = pre_season_html[:s] + pre_season_html[s+5:]
                        else:
                            break
                    while(True):
                        if '</div>' in pre_season_html:
                            s = pre_season_html.find('</div>')
                            pre_season_html = pre_season_html[:s] + pre_season_html[s+6:]
                        else:
                            break

                    pre_tier = list(pre_season_html.split(', ')) # 모든 시즌의 랭크 기록 저장
                    
                    # 직전 시즌 랭크 기록
                    self.data[i][3] = list(pre_tier[-1].split())[1].capitalize() if 'S2021' in pre_tier[-1] else "Unranked"
                    i += 1

    def show(self):
        os.system("cls")
        print("---          출 력          ---")
        for i in range(0, len(self.data)):
            print(str(i+1) + ". 이름 : " + self.data[i][0])
            print("     ID       : " + self.data[i][1])
            print("     Tier     : " + self.data[i][2])
            print("     Pre_Tier : " + self.data[i][3])

    def save(self):
        os.system("cls")
        try:
            with open("dataFile.csv", "w", encoding='utf-8-sig', newline='') as f:
                wr = csv.writer(f)
                for i in range(len(self.data)):
                    wr.writerow(self.data[i])
                print("저장되었습니다.")
        except:
            print("저장하지 못했습니다.")

    def load(self):
        os.system("cls")
        try:
            with open("dataFile.csv", "r",encoding='utf-8-sig') as f:
                rd = csv.reader(f)
                for item in rd:
                    # if(len(item) == 2):
                    #     item.append('')
                    #     item.append('')
                    u = user(item[:1], item[2:4], item[4:])
                    self.data.append(item)
                print("불러오기에 성공했습니다.")
        except:
            print("불러오지 못했습니다.")

# Main Process
app = Application()
app.run()