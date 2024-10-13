import args_parser
from interpreter import BrainduckInterpreter
from compiler import BrainduckCompiler
from execution_functions import compile_external_code
from execution_functions import interpret_external_code
from execution_functions import execute_shell
from sys import exit

#
VALID_OPTIONS: tuple[str, ...] = "debug", "compile"


def run(code_path: str | None, debug_mode: bool, compile_mode: bool):
    if compile_mode:
        compiler = BrainduckCompiler()
        compile_external_code(compiler, code_path, debug_mode)
        return

    interpreter = BrainduckInterpreter()
    if code_path:
        interpret_external_code(interpreter, code_path, debug_mode)
    else:
        execute_shell(interpreter, debug_mode)


if __name__ == '__main__':
    # Defining the variables
    code_path: str | None
    debug_mode: bool = False
    compile_mode: bool = False

    # Options
    # Testing if some option isn't valid
    if invalid_option := args_parser.has_invalid_option(VALID_OPTIONS):
        print(f"Error: Invalid option '{invalid_option}'")
        exit(0)

    # Setting the configs based on the selected options
    debug_mode = args_parser.option_pos("debug") != -1
    compile_mode = args_parser.option_pos("compile") != -1

    # Arguments
    # Getting the path, if it has one
    if len(args_parser.argv) > 1:
        code_path = args_parser.argv[-1]
    # If it doesn't, but is defined to compile the code, it will not run
    elif compile_mode is True:
        print("Error: The code can only be compiled if it has an source file.")
        exit(0)

    # Running the main function
    run(code_path, debug_mode, compile_mode)