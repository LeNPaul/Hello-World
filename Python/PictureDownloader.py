import random
import urllib

def download(url):
    name = random.randrange(1,1000)
    fullname = str(name) + ".jpg"
    urllib.urlretrieve(url, fullname,)

download("http://rulethewasteland.com/wp-content/uploads/2014/10/EDC-can-save-lives.jpg")