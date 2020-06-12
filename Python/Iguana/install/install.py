import shutil

iguanas = ['1','2','3','4','5','6','7','8','9','10']

for x in iguanas:
	shutil.copytree('iNTERFACEWARE-Iguana', '../iguana-' + x)
	shutil.copytree('IguanaMainRepo', '../iguana-' + x + '/IguanaMainRepo')
