import shutil
import os
import time

iguanas = ['01','02','03','04','05','06','07','08','09','10']

for x in iguanas:
        shutil.copytree('iNTERFACEWARE-Iguana', '../iguana-' + x)
        shutil.copytree('IguanaMainRepo', '../iguana-' + x + '/IguanaMainRepo')
        os.system('cd ~/iguana-' + x + '; ./iguana_service')
        time.sleep(3)

        os.system('sudo pkill -SIGTERM iguana_service')
        time.sleep(3)

        fin = open('/home/centos/iguana-' + x + '/IguanaConfigurationRepo/IguanaConfiguration.xml', 'rt')
        config = fin.read()
        config = config.replace('port="6543"', 'port="654' + x + '"')
        fin.close()

        fin = open('/home/centos/iguana-' + x + '/IguanaConfigurationRepo/IguanaConfiguration.xml', 'wt')
        fin.write(config)
        fin.close()

        os.rename('/home/centos/iguana-' + x + '/iguana_service', '/home/centos/iguana-' + x + '/iguana_service_' + x)
        os.rename('/home/centos/iguana-' + x + '/iguana_service.hdf', '/home/centos/iguana-' + x + '/iguana_service_' + x + '.hdf')
        os.system('cd ~/iguana-' + x + '; ./iguana_service_' + x)
