import re

def solution(new_id):
    answer = ''
    
    answer = new_id.lower()
    print("1단계 ", answer)
    
    answer = re.sub("[^a-z0-9-_.]", "", answer)
    print("2단계 ", answer)
    
    while ".." in answer : 
        answer = answer.replace("..", ".")
    
    print("3단계 ", answer)
    
    answer = answer[1:] if answer[0] == '.' and len(answer) > 1 else answer
    answer = answer[:-1] if answer[-1] == '.' else answer
    print("4단계 ", answer)
    
    if len(answer) == 0 : 
        answer = "a"
    print("5단계 ", answer)
        
    if len(answer) >= 16 : 
        answer = answer[:15]
        if answer[-1] == '.' : 
            answer = answer[:-1]
    print("6단계 ", answer)
        
    if len(answer) <= 2 : 
        while len(answer) < 3 : 
            answer = answer + answer[-1]
    print("7단계 ", answer)
    
    return answer