#LE O OUTPUT DO JUDGE EM TXT NA PASTA /SOL E GUARDA RESULTADOS
import os
import re
import json
root = './sol'
list_pass= [] 
list_CE= []
list_EE= []
list_TLE= []
list_MLE= []
score = {}
errors = {}

# Load lists and dictionaries from JSON files
with open('./results/list_pass.json', 'r', encoding='utf-8') as f:
    list_pass = json.load(f)

with open('./results/list_CE.json', 'r', encoding='utf-8') as f:
    list_CE = json.load(f)

with open('./results/list_EE.json', 'r', encoding='utf-8') as f:
    list_EE = json.load(f)

with open('./results/list_TLE.json', 'r', encoding='utf-8') as f:
    list_TLE = json.load(f)

with open('./results/list_MLE.json', 'r', encoding='utf-8') as f:
    list_MLE = json.load(f)

with open('./results/score.json', 'r', encoding='utf-8') as f:
    score = json.load(f)

with open('./results/errors.json', 'r', encoding='utf-8') as f:
    errors = json.load(f)

def get_results():
    for file in os.listdir(root):
        if file.endswith('.txt') and file[:-4] not in score:
            with open(os.path.join(root, file), 'r', encoding='utf-8') as f:
                content = f.read()
                file = file[:-4]
                error = content.split('Saída de erro padrão (stderr):')[-1].rstrip()
                if len(error)>0:
                    errors[file] = error
                search = re.search(r'Pontuação.*100', content)
                score[file] = int(search.group().split()[-3])
                if 'Compilação terminou com sucesso' not in content:
                    list_CE.append(file)
                    continue
                search = re.search(r'Limite de tempo permitido.*s', content)
                time_lim = float(search.group().split()[-2].replace(',','.'))
                search = re.search(r'Máximo tempo usado.*s', content)
                time_exe = float(search.group().split()[-2].replace(',','.'))
                if time_exe >= time_lim:
                    list_TLE.append(file)
                    continue
                search = re.search(r'Limite de memória permitido.*B', content)
                mem_lim,unit = search.group().split()[-2:]
                mem_lim = float(mem_lim)
                if unit == 'MB':
                    mem_lim *= 1000
                elif unit == 'GB':
                    mem_lim *= 1000000
                elif unit != 'KB':
                    print(f'ERRO {file}')
                search = re.search(r'Máxima memória usada.*B', content)
                mem_exe,unit = search.group().split()[-2:]
                mem_exe = float(mem_exe)
                if unit == 'MB':
                    mem_lim *= 1000
                elif unit == 'GB':
                    mem_lim *= 1000000
                elif unit != 'KB':
                    print(f'ERRO {file}')
                if mem_exe >= mem_lim:
                    list_MLE.append(file)
                    continue
                if len(error)>0:
                    list_EE.append(file)
                else:
                    list_pass.append(file)
                
    # Write lists and dictionaries to JSON files
    with open('./results/list_pass.json', 'w', encoding='utf-8') as f:
        json.dump(list_pass, f, ensure_ascii=False, indent=4)

    with open('./results/list_CE.json', 'w', encoding='utf-8') as f:
        json.dump(list_CE, f, ensure_ascii=False, indent=4)

    with open('./results/list_EE.json', 'w', encoding='utf-8') as f:
        json.dump(list_EE, f, ensure_ascii=False, indent=4)

    with open('./results/list_TLE.json', 'w', encoding='utf-8') as f:
        json.dump(list_TLE, f, ensure_ascii=False, indent=4)

    with open('./results/list_MLE.json', 'w', encoding='utf-8') as f:
        json.dump(list_MLE, f, ensure_ascii=False, indent=4)

    with open('./results/score.json', 'w', encoding='utf-8') as f:
        json.dump(score, f, ensure_ascii=False, indent=4)

    with open('./results/errors.json', 'w', encoding='utf-8') as f:
        json.dump(errors, f, ensure_ascii=False, indent=4)