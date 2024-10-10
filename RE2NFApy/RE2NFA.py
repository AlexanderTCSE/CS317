import sys

#NFA class definition
class NFA:
    def __init__(self,start,accept,transitions):
        self.start = start
        self.accept = accept
        self.transitions = transitions

#State transition class definition
class Transition:
    def __init__(self,state1,state2,symbol):
        self.state1 = state1
        self.state2 = state2
        self.symbol = symbol

    def __repr__(self):
        # Format the transition for output
        return f"({self.state1}, {'E' if self.symbol == '' else self.symbol}) → {self.state2}"


def readFile():
    #make sure correct number of arguments are passed
    if len(sys.argv) != 2:
        print("Usage: python3 RE2NFA <file>")
        sys.exit(1)

    #check that file is a .txt file
    if not sys.argv[1].endswith('.txt'):
        print("Error: Must supply a .txt file")
        sys.exit(1)

    #try to open file
    try:
        with open(sys.argv[1],'r') as file:
            lines = file.readlines()
            return lines
    except FileNotFoundError:
        print(f"Error: File {sys.argv[1]} not found.")
        sys.exit(1)

def parseExpression(expression): 
    stack = []              #init empty stack
    language = set('abcde') #valid language
    stateCount = 1          #counter for state names

    #outpute RE
    print(f"RE: {expression}")

    #begin evaluating expression
    for char in expression:     #for each character per line
        #if char is in language, push to stack
        if char in language:
            startState = f'q{stateCount}'
            acceptState = f'q{stateCount + 1}'
            transition = Transition(startState, acceptState, char)
            transitions = [transition]
            nfa = NFA(startState, acceptState, transitions)
            stack.append(nfa)
            stateCount += 2
          
        #else, char is operator, manipulate stack accordingly
        else:
            #binary operators need at least 2 operands
            if len(stack) < 2 and char != '*':
                print("Error: malformed input. Not enough operands.")
                return

            #actual evaluations begin here
            if char == '|': #Union OR operator
                operand2 = stack.pop()
                operand1 = stack.pop()
                result = NFA(f'q{stateCount}', f'q{stateCount+1}', [])
                result.transitions.append(Transition(result.start, operand1.start, '')) # Epsilon transition
                result.transitions.append(Transition(result.start, operand2.start, ''))
                result.transitions.extend(operand1.transitions) # Add operand1 transitions
                result.transitions.extend(operand2.transitions) # Add operand2 transitions
                result.transitions.append(Transition(operand1.accept, result.accept, ''))
                result.transitions.append(Transition(operand2.accept, result.accept, ''))
                stack.append(result)
                stateCount += 2
                
            elif char == '&': #Intersection AND operator
                operand2 = stack.pop()
                operand1 = stack.pop() 
                result = NFA(f'q{stateCount}', operand2.accept, [])
                result.transitions.extend(operand1.transitions) # Add operand1 transitions
                result.transitions.append(Transition(operand1.accept, operand2.start, ''))
                result.transitions.extend(operand2.transitions) # Add operand2 transitions
                stack.append(result) # Push the resulting NFA onto the stack 
                stateCount += 2
                
            elif char == '*': #Kleene star operator
                if len(stack) < 1:
                    print("Error: malformed input. Not enough operands.")
                    return
                operand = stack.pop()
                result = NFA(f'q{stateCount}', f'q{stateCount}', []) # New NFA for the result
                result.transitions.append(Transition(result.start, operand.start, '')) # Epsilon transition
                result.transitions.extend(operand.transitions) # Add operand transitions
                result.transitions.append(Transition(operand.accept, result.start, ''))
                result.transitions.append(Transition(result.start, f'q{stateCount+1}', ''))
                stack.append(result) # Push the resulting NFA onto the stack
                stateCount += 1
                
            else:
                print(f"Error: unknown operator {char}")
                return

    if len(stack) != 1:
        print("Error: malformed input. Stack is not empty.")
    else:
        final_nfa = stack.pop()
        print(f"Start: {final_nfa.start}")    # Output the Start state
        print(f"Accept: {final_nfa.accept}")  # Output the Accept state
        # Sort transitions and print them
        sorted_transitions = sorted(final_nfa.transitions, key=lambda t: (t.state1, t.symbol, t.state2))
        for transition in sorted_transitions:
            print(transition)  # Print each transition

    
def processLines():
    lines = readFile()
    for line in lines:
        expression = line.strip()
        print(f"Evaluating: {expression}")
        parseExpression(expression)
        print()

processLines()
