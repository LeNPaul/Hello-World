import urllib

googurl = "http://real-chart.finance.yahoo.com/table.csv?s=GOOG&d=11&e=26&f=2014&g=d&a=2&b=27&c=2014&ignore=.csv"

def downloaddata(csvurl):
    response = urllib.urlopen(csvurl)
    csv = response.read()
    csvstr = str(csv)
    lines = csvstr.split("\\n")
    desturl = r"test.csv"
    fx = open("googurl", "w")
    for line in lines:
        fx.write(line + "\n")
        fx.close()

downloaddata(googurl)