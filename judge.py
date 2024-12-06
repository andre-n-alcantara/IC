#LE O OUTPUT DO JUDGE EM TXT NA PASTA /SOL E GUARDA RESULTADOS
import os, re
root = './sol'
list_pass= [] 
list_CE= []
list_EE= []
list_TLE= []
list_MLE= []
score = {}
errors = {}
for file in os.listdir(root):
    if file.endswith('.txt') and file[:-4] not in score:
        with open(os.path.join(root, file), 'r') as f:
            content = f.read()
            file = file[:-4]
            error = content.split('Saída de erro padrão (stderr):')[-1].rstrip()
            if len(error)>0:
                errors[file] = error
            search = re.search(r'Pontuação \d+ / 100', content)
            score[file] = int(search.group().split()[-3])
            if 'Compilação terminou com sucesso' not in content:
                list_CE.append(file)
                continue
            search = re.search(r'Limite de tempo permitido .+ s', content)
            time_lim = float(search.group().split()[-2].replace(',','.'))
            search = re.search(r'Máximo tempo usado .+ s', content)
            time_exe = float(search.group().split()[-2].replace(',','.'))
            if time_exe >= time_lim:
                list_TLE.append(file)
                continue
            search = re.search(r'Limite de memória permitido .+ .B', content)
            mem_lim,unit = float(search.group().split()[-2:])
            if unit == 'MB':
                mem_lim *= 1000
            elif unit == 'GB':
                mem_lim *= 1000000
            search = re.search(r'Máxima memória usada .+ .B', content)
            mem_exe,unit = float(search.group().split()[-2:])
            if unit == 'MB':
                mem_lim *= 1000
            elif unit == 'GB':
                mem_lim *= 1000000
            if mem_exe >= mem_lim:
                list_MLE.append(file)
                continue
            if len(error)>0:
                list_EE.append(file)
            else:
                list_pass.append(file)
            

