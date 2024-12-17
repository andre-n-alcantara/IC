import os
import re

def add_ctime(directory):
    for filename in os.listdir(directory):
        if filename.endswith(".cpp"):
            filepath = os.path.join(directory, filename)
            with open(filepath, 'r') as file:
                content = file.read()

            # Check if #include <ctime> is already present
            if '#include <ctime>' not in content:
                content = '#include <ctime>\n' + content

            # Find all occurrences of "int main"
            main_occurrences = [m.start() for m in re.finditer(r'\bint\s+main\b', content)]

            for main_pos in main_occurrences:
                # Check if "int main" is commented out
                line_start = content.rfind('\n', 0, main_pos) + 1
                line_end = content.find('\n', main_pos)
                line = content[line_start:line_end]

                # Check for "//" on the same line
                if '//' in line:
                    continue

                # Check for "/*" without a "*/" in between
                before_main = content[:main_pos]
                after_main = content[main_pos:]
                if before_main.count('/*') > before_main.count('*/'):
                    continue

                # If we reach here, it means "int main" is not commented out
                # Find the first "{" after "int main"
                brace_pos = content.find('{', main_pos)
                if brace_pos != -1:
                    content = content[:brace_pos + 1] + '\n    std::clock_t startTime = std::clock();' + content[brace_pos + 1:]

                    # Find the first "return 0;" after "int main"
                    return_pos = content.find('return 0;', brace_pos)
                    if return_pos != -1:
                        timing_code = """
    std::clock_t endTime = std::clock();
    std::clock_t clockTicksTaken = endTime - startTime;
    double timeInSeconds = clockTicksTaken / (double) CLOCKS_PER_SEC;
    std::cout << "timeInSeconds: " << timeInSeconds << '\\n';
"""
                        content = content[:return_pos] + timing_code + content[return_pos:]
                    break  # We only need to modify the first valid "int main"

            # Write the modified content back to the file
            with open(filepath, 'w') as file:
                file.write(content)

# Example usage
directory = './sol'  # Replace with the path to your directory
add_ctime(directory)