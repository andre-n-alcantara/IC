import re

def read_conversation_history(filename):
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

# Example usage
filename = '2021-pj-f3-plano2.txt'
conversation_history = read_conversation_history(filename)
for di in conversation_history[:3]:
    print('{"role":', di['role'],'}')
    print('{"content":', di['content'],'}')