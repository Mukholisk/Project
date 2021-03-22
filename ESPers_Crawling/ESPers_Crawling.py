# ... iss Crew
# ... Made By Mukho
# ... 2021-03-22 MON
# ... Last Update : 2021-03-22 MON
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
        while i < len(self.data):           
            # url로 크롤링
            url = "https://www.op.gg/summoner/userName=" + parse.quote(self.data[i][1])
            req = request.urlopen(url)
            soup = bs4.BeautifulSoup(req, 'html.parser')
            isError = False # 잘못된 아이디인가
            # op.gg에 등록되지 않은 아이디인가?
            if str(type(soup.find('h2'))) == "<class 'NoneType'>":
                if str(type(soup.find('div', 'ChampionImage'))) == "<class 'NoneType'>": # 등록은 되어있지만 전적이 없는 아이디인가?
                    isError = True
                else:
                    isError = False
            elif soup.find('h2').text == "This summoner is not registered at OP.GG. Please check spelling.": # 등록이 안되어 있는가?
                isError = True
            
            # 잘못된 아이디
            if isError:
                print("op.gg에 등록되지 않은 소환사입니다. '" + self.data[i][1] + "' id의 데이터를 삭제합니다.")
                del self.data[i]
                if i != 0:
                    i -= 1
            else:
                self.data[i][1] = soup.find('div', 'Information').find('span', 'Name').text # id
                self.data[i][2] = soup.find("div", {"class":"TierRank"}).text.strip() # tier
                s = 0
                e = -1
                pre_tier = "" # pre tier
                try: # 전 시즌 티어 가져오기
                    pre_tier_s = soup.find("div", "PastRank").find_all("li")
                    pre_tier_str = str(pre_tier_s[-1])

                    if("S2020" in pre_tier_str):
                        s = pre_tier_str.find("title=")+7
                        if pre_tier_str[s:].find("Iron") != -1:
                            e = pre_tier_str[s:].find("Iron")+6
                        elif pre_tier_str[s:].find("Bronze") != -1:
                            e = pre_tier_str[s:].find("Bronze")+8
                        elif pre_tier_str[s:].find("Silver") != -1:
                            e = pre_tier_str[s:].find("Silver")+8
                        elif pre_tier_str[s:].find("Gold") != -1:
                            e = pre_tier_str[s:].find("Gold")+6
                        elif pre_tier_str[s:].find("Platinum") != -1:
                            e = pre_tier_str[s:].find("Platinum")+10
                        elif pre_tier_str[s:].find("Diamond") != -1:
                            e = pre_tier_str[s:].find("Diamond")+9
                        elif pre_tier_str[s:].find("Master") != -1:
                            e = pre_tier_str[s:].find("Master")+7
                        elif pre_tier_str[s:].find("Grandmaster") != -1:
                            e = pre_tier_str[s:].find("Grandmaster")+12
                        elif pre_tier_str[s:].find("Challenger") != -1:
                            e = pre_tier_str[s:].find("Challenger")+11
                        else:
                            pre_tier = "Unranked"
                        pre_tier = pre_tier_str[s:s+e]
                    else:
                        pre_tier = "Unranked"     
                except:
                    pre_tier = "Unranked" # 예외처리
                self.data[i][3] = pre_tier
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
                    if(len(item) == 2):
                        item.append('')
                        item.append('')
                    self.data.append(item)
                print("불러오기에 성공했습니다.")
        except:
            print("불러오지 못했습니다.")

# Main Process
app = Application()
app.run()