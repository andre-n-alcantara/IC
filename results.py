#LE O OUTPUT DO JUDGE EM TXT NA PASTA /SOL E GUARDA RESULTADOS
import os
import re
import json

def info(codigo):
    edicao, nivel, fase, nome = codigo.split('_',3)
    return edicao, nivel, fase, nome
     
def get_results():
    root = './sol'
    results = {}
    for file in os.listdir(root):
        codigo = file.rsplit('.',1)[0]
        results[codigo] = { 
            "pontuacao" : None,
            "n_subtarefas" : None,
            "subtarefas100" : None,
            "tempo_lim" : None,
            "mem_lim" : None,
            "tempo" : None,
            "mem" : None,
            "comp" : None,
            "stderr" : None 
        }
        path = os.path.join(root,file)
        content = ''
        with open(path, 'r', encoding='utf-8') as f:
            content = f.read()
        if 'Resumo da correção' not in content or 'Saída de erro padrão (stderr):' not in content:
            print(f'{codigo} com erro.')
            return None
        results[codigo]["stderr"] = content.split('Saída de erro padrão (stderr):')[1]
        comp = 'Compilação terminou com falha' not in content
        results[codigo]["comp"] = comp 
        if not comp:
            continue
        results[codigo]["n_subtarefas"] = content.count('Subtarefa')
        subtarefas = re.findall(r'Subtarefa \d+\s+\d+ / \d+', content)
        subtarefas100 = 0
        for tarefa in subtarefas:
            splitted = tarefa.split(' / ')
            if splitted[0].split()[-1] == splitted[1]:
                subtarefas100 += 1
        results[codigo]["subtarefas100"] = subtarefas100
        results[codigo]["pontuacao"] = int(re.search(r'Pontuação \d+', content).group().split()[1])
        mem_lim,unit1 = re.search(r'Limite de memória permitido.*B', content).group().split()[-2:]
        mem,unit2 = re.search(r'Máxima memória usada.*B', content).group().split()[-2:]
        convert = {"KB": 1, "MB": 1000, "GB": 1000000}
        if unit1 not in convert.keys() or unit2 not in convert.keys():
            print(f'{codigo} com unidade inválida.')
            return None
        results[codigo]["mem_lim"] = float(mem_lim)*convert[unit1]
        results[codigo]["mem"] = float(mem)*convert[unit2]
        results[codigo]["tempo_lim"] = float(re.search(r'Limite de tempo permitido.*s', content).group().split()[-2].replace(',','.'))
        results[codigo]["tempo"] = float(re.search(r'Máximo tempo usado.*s', content).group().split()[-2].replace(',','.'))
        for key in results[codigo].keys():
            if results[codigo][key] == None:
                print(f'{key} de {codigo} vazio.')
                return None
                    
    return results

results =  get_results()
with open('./results.json', 'w', encoding='utf-8') as f:
    json.dump(results, f, ensure_ascii=False, indent=4)
