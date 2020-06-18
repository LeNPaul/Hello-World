import shutil
import os
import time

# Suffix for differentiating Iguana instances
iguanas = ['01','02','03','04','05','06','07','08','09','10']

for x in iguanas:
        # Create a copy of the Iguana application files and rename to include the suffic
        shutil.copytree('iNTERFACEWARE-Iguana', '../iguana-' + x)
        # Copy the IguanaMainRepo with the pre-configured channels
        shutil.copytree('IguanaMainRepo', '../iguana-' + x + '/IguanaMainRepo')
        # Start the Iguana service to generate the IguanaConfigurationRepo
        os.system('cd ~/iguana-' + x + '; ./iguana_service')
        time.sleep(3)
        # Stop the Iguana service
        os.system('sudo pkill -SIGTERM iguana_service')
        time.sleep(3)
        # Change the port number for the Iguana instance to avoid conflicts
        fin = open('/home/centos/iguana-' + x + '/IguanaConfigurationRepo/IguanaConfiguration.xml', 'rt')
        config = fin.read()
        config = config.replace('port="6543"', 'port="654' + x + '"')
        fin.close()
        fin = open('/home/centos/iguana-' + x + '/IguanaConfigurationRepo/IguanaConfiguration.xml', 'wt')
        fin.write(config)
        fin.close()
        # Rename the iguana_service and iguana_service.hdf to something more descriptive
        os.rename('/home/centos/iguana-' + x + '/iguana_service', '/home/centos/iguana-' + x + '/iguana_service_' + x)
        os.rename('/home/centos/iguana-' + x + '/iguana_service.hdf', '/home/centos/iguana-' + x + '/iguana_service_' + x + '.hdf')
