#LE O REGISTRO DO CHAT EM TXT E RECUPERA O DICIONARIO DE CONTEXTO PARA CONTINUAR A CONVERSA
import re
import json

def get_conversation_history(filename):
    conversation_history = []
    with open(filename, 'r', encoding='utf-8') as file:
        content = file.read()
        
        # Regular expression to match sequences of 50+ hyphens
        hyphen_pattern = re.compile(r'-{50}-*')
        
        # Split the content by "User:" and process each part
        user_parts = content.split("User:")
        for part in user_parts[1:]:  # Skip the first part as it doesn't start with "User:"
            user_content = part.split("AI:")[0].strip()
            ai_part = part.split("AI:")[1]
            ai_content = hyphen_pattern.split(ai_part)[0].strip()
            
            conversation_history.append({
                'role': 'user',
                'content': user_content
            })
            conversation_history.append({
                'role': 'assistant',
                'content': ai_content
            })
    
    return conversation_history

filename = ''
conversation_history = get_conversation_history(filename)
with open('conversation_history.json', 'w', encoding='utf-8') as f:
    json.dump(conversation_history, f, ensure_ascii=False, indent=4)