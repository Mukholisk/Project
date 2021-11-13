import bs4
import urllib.parse as parse
import urllib.request as request
import os

urlList = [
    'https://news.google.com/topics/CAAqJggKIiBDQkFTRWdvSUwyMHZNRFZxYUdjU0FtdHZHZ0pMVWlnQVAB?hl=ko&gl=KR&ceid=KR%3Ako',
    'https://news.google.com/topics/CAAqIQgKIhtDQkFTRGdvSUwyMHZNRFp4WkRNU0FtdHZLQUFQAQ?hl=ko&gl=KR&ceid=KR%3Ako',
    'https://news.google.com/topics/CAAqJggKIiBDQkFTRWdvSUwyMHZNRFZxYUdjU0FtdHZHZ0pMVWlnQVAB/sections/CAQiRkNCQVNMZ29JTDIwdk1EVnFhR2NTQW10dkdnSkxVaUlPQ0FRYUNnb0lMMjB2TURsdWJWOHFDZ29JRWdic2hManFzNFFvQUEqKggAKiYICiIgQ0JBU0Vnb0lMMjB2TURWcWFHY1NBbXR2R2dKTFVpZ0FQAVAB?hl=ko&gl=KR&ceid=KR%3Ako',
    'https://news.google.com/topics/CAAqJggKIiBDQkFTRWdvSUwyMHZNRFZxYUdjU0FtdHZHZ0pMVWlnQVAB/sections/CAQiTkNCQVNOQW9JTDIwdk1EVnFhR2NTQW10dkdnSkxVaUlPQ0FRYUNnb0lMMjB2TURsek1XWXFFQW9PRWd6cnVZVHNwb2pyaTRqc2lxUW9BQSoqCAAqJggKIiBDQkFTRWdvSUwyMHZNRFZxYUdjU0FtdHZHZ0pMVWlnQVABUAE?hl=ko&gl=KR&ceid=KR%3Ako',
    'https://news.google.com/topics/CAAqJggKIiBDQkFTRWdvSUwyMHZNRFZxYUdjU0FtdHZHZ0pMVWlnQVAB/sections/CAQiUENCQVNOZ29JTDIwdk1EVnFhR2NTQW10dkdnSkxVaUlQQ0FRYUN3b0pMMjB2TUdabWR6Vm1LaEVLRHhJTjZyTzg3WldaTC1xNHNPeUlvQ2dBKioIAComCAoiIENCQVNFZ29JTDIwdk1EVnFhR2NTQW10dkdnSkxVaWdBUAFQAQ?hl=ko&gl=KR&ceid=KR%3Ako',
    'https://news.google.com/topics/CAAqJggKIiBDQkFTRWdvSUwyMHZNRFZxYUdjU0FtdHZHZ0pMVWlnQVAB/sections/CAQiVkNCQVNPZ29JTDIwdk1EVnFhR2NTQW10dkdnSkxVaUlPQ0FRYUNnb0lMMjB2TURKcWFuUXFGZ29VRWhMc2w1VHRoTER0aFl6c25ianJxTHp0aXJnb0FBKioIAComCAoiIENCQVNFZ29JTDIwdk1EVnFhR2NTQW10dkdnSkxVaWdBUAFQAQ?hl=ko&gl=KR&ceid=KR%3Ako',
    'https://news.google.com/topics/CAAqJggKIiBDQkFTRWdvSUwyMHZNRFZxYUdjU0FtdHZHZ0pMVWlnQVAB/sections/CAQiSkNCQVNNUW9JTDIwdk1EVnFhR2NTQW10dkdnSkxVaUlPQ0FRYUNnb0lMMjB2TURadWRHb3FEUW9MRWduc2lxVHRqNnpzdUtBb0FBKioIAComCAoiIENCQVNFZ29JTDIwdk1EVnFhR2NTQW10dkdnSkxVaWdBUAFQAQ?hl=ko&gl=KR&ceid=KR%3Ako',
    'https://news.google.com/topics/CAAqJggKIiBDQkFTRWdvSUwyMHZNRFZxYUdjU0FtdHZHZ0pMVWlnQVAB/sections/CAQiRkNCQVNMZ29JTDIwdk1EVnFhR2NTQW10dkdnSkxVaUlPQ0FRYUNnb0lMMjB2TUd0ME5URXFDZ29JRWdicXNiVHFzSlVvQUEqKggAKiYICiIgQ0JBU0Vnb0lMMjB2TURWcWFHY1NBbXR2R2dKTFVpZ0FQAVAB?hl=ko&gl=KR&ceid=KR%3Ako'
]

# 뉴스 데이터가 없을 가능성이 없다고 가정
f = open('titleData.txt', 'w')
id = 0

for i in range(8):
    url = urlList[i]
    req = request.urlopen(url)
    soup = bs4.BeautifulSoup(req, 'html.parser')
    title = soup.find_all('a', 'DY5T1d RZIKme')
    
    for data in(title):
        text = str(id) + ' ' + data.get_text() + '\n'
        f.write(text)
        id = id + 1

f.close()
print("Crawling Finished")