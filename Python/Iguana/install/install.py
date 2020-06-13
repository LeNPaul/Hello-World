import os

iguanas = ['1','2','3','4','5','6','7','8','9','10']

f = open('test.txt', 'wb')
f.write('hello world')
f.close()

for x in iguanas:
        shutil.copytree('iNTERFACEWARE-Iguana', '../iguana-' + x)
        shutil.copytree('IguanaMainRepo', '../iguana-' + x + '/IguanaMainRepo')
        os.system('cd ~/iguana-' + x + '; ./iguana_service')
        os.system('sudo pkill -SIGTERM iguana_service')
