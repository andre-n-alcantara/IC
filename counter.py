import os
import json
directory = os.listdir('./pratique')
for entry in directory:
    if entry.endswith('.txt') and entry[:-4]+'.cpp' not in directory:
        newname = entry[:-4]+'.cpp'
        path = os.path.join('./sol',newname)
        newpath = os.path.join('./pratique',newname)
        with open(path, 'r') as f:
            content = f.read()
        with open(newpath,'w') as f2:
            f2.write(content)
        os.remove(path)
        print(path)

