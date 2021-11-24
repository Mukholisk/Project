# https://velog.io/@jungeun-dev/Python-%EC%9B%B9-%ED%81%AC%EB%A1%A4%EB%A7%81Selenium-%EA%B5%AC%EA%B8%80-%EC%9D%B4%EB%AF%B8%EC%A7%80-%EC%88%98%EC%A7%91
# find_element(s)_by_* -> find_element(s)

from selenium import webdriver
from selenium.webdriver.common.by import By # New Version
from selenium.webdriver.common.keys import Keys
import time
import urllib.request
import os

# 폴더 생성
def createDirectory(directory):
    try:
        if not os.path.exists(directory):
            os.makedirs(directory)
    except OSError:
        print("Error: Failed to create the directory.")

def crawling_img(name):
    # 크롬 브라우저 열기
    driver = webdriver.Chrome(executable_path='./chromedriver')
    driver.get("https://www.google.co.kr/imghp?hl=ko&tab=wi&authuser=0&ogbl")
    elem = driver.find_element(By.NAME, "q")
    elem.send_keys(name)
    elem.send_keys(Keys.RETURN)

    SCROLL_PAUSE_TIME = 1
    # Get scroll height
    last_height = driver.execute_script("return document.body.scrollHeight")  # 브라우저의 높이를 자바스크립트로 찾음
    while True:
        # Scroll down to bottom
        driver.execute_script("window.scrollTo(0, document.body.scrollHeight);")  # 브라우저 끝까지 스크롤을 내림
        # Wait to load page
        time.sleep(SCROLL_PAUSE_TIME)
        # Calculate new scroll height and compare with last scroll height
        new_height = driver.execute_script("return document.body.scrollHeight")
        if new_height == last_height:
            try:
                driver.find_element(By.CSS_SELECTOR, ".mye4qd").click()
            except:
                break
        last_height = new_height

    # 이미지 검색창의 모든 이미지들 저장
    imgs = driver.find_elements(By.CSS_SELECTOR, ".rg_i.Q4LuWd")
    print(imgs[0])

    # 이미지를 저장할 폴더 생성
    dir = ".\img" + "\\" + name
    createDirectory(dir) # 폴더 생성

    # count 수 만큼 반복
    count = 1
    for img in imgs:
        try:
            img.click()
            time.sleep(2)
            # 사이트에 있는 이미지의 url값
            imgUrl = driver.find_element(By.XPATH, '//*[@id="Sva75c"]/div/div/div[3]/div[2]/c-wiz/div/div[1]/div[1]/div[2]/div[1]/a/img').get_attribute("src")
            # 저장할 경로
            path = "C:\\Users\\KoMoGoon\\Documents\\GitHub\\Project\\Google_Image_Crawling\\img\\" + name + "\\"
            # 경로 + 파일명 + 파일 확장자
            saveName = path + name + str(count) + ".jpg"
            # 파일 저장
            urllib.request.urlretrieve(imgUrl, saveName)

            # 반복
            count = count + 1
            if count >= 10000:
                break
        except:
            pass
    driver.close()
    print("["+name+"]"+" Crawling Finished.")

"""
검색어 목록을 search 리스트 안에 넣고 실행.
count 수만큼 자동으로 사진 클릭->저장 Cycle을 반복함
"""
search = ["아이즈원 김채원"] 

for s in search:
    crawling_img(s)