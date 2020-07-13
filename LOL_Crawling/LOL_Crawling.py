# ... iss Crew
# ... Made By Mukho
# ... 2020-07-11 SAT
# ... Last Update : 2020-07-13 MON
# ... Recovering LOL_Crawing(2018)_CUI version.

# 2018년 5월에 만들었던 ESPers_LOL.exe의 소스 코드가 사라져 다시 만듬.
# 그때보다 파이썬 문법은 더 많이 알지만, 더 어렵게 만든듯 ㄹㅇㅋㅋ
# op.gg 서버 등록 id 기준으로 검색하기 때문에 null값이 입력될 가능성이 존재한다.

#-*-coding: utf-8 -*-
import bs4
import urllib.parse as parse
import urllib.request as request
import os

class Application:
    def __init__(self):
        #data = [ [name, ID, tier, Most1, Most2, Most3, Most4, Most5], ..., [] ]
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
            temp = [name, id, '', '', '', '', '', ''] # 사용자로부터 이름과 id만 입력받고, 나머지 값은 ''로 초기화
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
                # 언랭은 모스트 출력 지원 안함
                if self.data[i][2] != "Unranked":
                    for j in range(0,5):
                        try: # most 정보가 있으면 저장
                            temp = str(soup.find('div', 'MostChampionContent').find_all('img')[j])
                            a = temp.find("/champion/")
                            b = temp.find(".png")
                            self.data[i][j+3] = temp[a+10:b]
                        except:
                            break # 예외처리
                i += 1

    def show(self):
        os.system("cls")
        print("---          출 력          ---")
        for i in range(0, len(self.data)):
            print(str(i+1) + ". 이름 : " + self.data[i][0])
            print("     ID     : " + self.data[i][1])
            print("     Tier   : " + self.data[i][2])
            print("     Most 1 : " + self.data[i][3])
            print("     Most 2 : " + self.data[i][4])
            print("     Most 3 : " + self.data[i][5])
            print("     Most 4 : " + self.data[i][6])
            print("     Most 5 : " + self.data[i][7])

    def save(self):
        try:
            with open("dataFile.txt", "w") as f:
                for i in range(len(self.data)):
                    if i != 0:
                        f.write("\n")
                    text = "\n".join(self.data[i])
                    f.write(text)
                print("저장되었습니다.")
        except:
            print("저장하지 못했습니다.")

    def load(self):
        try:
            with open("dataFile.txt", "r") as f:
                temp = []
                cnt = 0
                for item in f:
                    temp.append(item.rstrip('\n'))
                    cnt += 1
                    if cnt == 8:
                        self.data.append(temp)
                        temp = []
                        cnt = 0
                print("불러오기에 성공했습니다.")
        except:
            print("불러오지 못했습니다.")

# Main Process
app = Application()
app.run()