CC = g++
NAME = program
TEST_NAME = program_tests
CFLAGS = --std=c++17 -Wall --coverage
DEBUG_FLAG =

BUILD_DIR = ./build
BUILD_TEST_DIR = /build
DOC_DIR = ./docs
INCLUDE_DIR = ./include
RES_DIR = /res
SRC_DIR = ./src
TEST_DIR = ./tests
COVERAGE_DIR = ./coverage
THIRD_DIR = ./third_party

BUILD_FILES = \
	$(BUILD_DIR)/GerenciaCarteira.o \
	$(BUILD_DIR)/Barricada.o \
	$(BUILD_DIR)/Transferencia.o \
	$(BUILD_DIR)/Carteira.o \
	$(BUILD_DIR)/CarteiraBancaria.o \
	$(BUILD_DIR)/Receita.o \
	$(BUILD_DIR)/Despesa.o \
	$(BUILD_DIR)/Transferencia.o \
	$(BUILD_DIR)/Transacao.o \
	$(BUILD_DIR)/CartaoDeCredito.o \
	$(BUILD_DIR)/CartaoDeCreditoExcp.o \
	$(BUILD_DIR)/GerenciaCarteiraExcp.o \
	$(BUILD_DIR)/TransacaoExcp.o \
	$(BUILD_DIR)/Utils.o \
	$(BUILD_DIR)/CarteiraExcp.o \
	$(BUILD_DIR)/ValidarEntrada.o \
	$(BUILD_DIR)/main.o

TEST_DEPENDENCIES = \
	$(BUILD_DIR)/Transacao.o \
	$(BUILD_DIR)/Carteira.o \
	$(BUILD_DIR)/Receita.o \
	$(BUILD_DIR)/Despesa.o \
	$(BUILD_DIR)/Transferencia.o \
	$(BUILD_DIR)/CartaoDeCredito.o \
	$(BUILD_DIR)/CartaoDeCreditoExcp.o \
	$(BUILD_DIR)/TransacaoExcp.o \
	$(BUILD_DIR)/Utils.o \
	$(BUILD_DIR)/CarteiraExcp.o \
	$(BUILD_DIR)/CarteiraBancaria.o \
	$(BUILD_DIR)/ValidarEntrada.o \
	
BUILD_TEST_FILES = \
	$(TEST_DIR)$(BUILD_TEST_DIR)/TesteCartaoDeCredito.o \
	$(TEST_DIR)$(BUILD_TEST_DIR)/TesteCarteira.o \
	$(TEST_DIR)$(BUILD_TEST_DIR)/TesteCarteiraBancaria.o \
	$(TEST_DIR)$(BUILD_TEST_DIR)/TesteReceita.o \
	$(TEST_DIR)$(BUILD_TEST_DIR)/TesteDespesa.o \
	$(TEST_DIR)$(BUILD_TEST_DIR)/TesteTransferencia.o \
	$(TEST_DIR)$(BUILD_TEST_DIR)/main_test.o 

all: $(BUILD_DIR)/$(NAME)

$(BUILD_DIR)/$(NAME): $(BUILD_FILES)
	$(CC) $(CFLAGS) $(DEBUG_FLAG) $(BUILD_DIR)/*.o -o $(BUILD_DIR)/$(NAME)

$(BUILD_DIR)/%.o: $(SRC_DIR)$(RES_DIR)/%.cpp $(INCLUDE_DIR)/%.hpp
	$(CC) -c $(CFLAGS) $(DEBUG_FLAG) $< -I $(INCLUDE_DIR) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $(DEBUG_FLAG) $< -I $(INCLUDE_DIR) -o $@

debug: clean_build var all

var:
	$(eval DEBUG_FLAG = -g)

run: all
	$(BUILD_DIR)/$(NAME)

tests: mkdir_test_build ${TEST_DIR}$(BUILD_TEST_DIR)/${TEST_NAME}

$(TEST_DIR)$(BUILD_TEST_DIR)/%.o: $(TEST_DIR)$(RES_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -I $(INCLUDE_DIR) -I $(THIRD_DIR) -o $@

$(TEST_DIR)$(BUILD_TEST_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) -c $(CFLAGS) $< -I $(INCLUDE_DIR) -I $(THIRD_DIR) -o $@

${TEST_DIR}$(BUILD_TEST_DIR)/${TEST_NAME}: $(TEST_DEPENDENCIES) $(BUILD_TEST_FILES)
	$(CC) $(CFLAGS) $(TEST_DEPENDENCIES) $(TEST_DIR)$(BUILD_TEST_DIR)/*.o -o $@

mkdir_test_build:
	mkdir -p ${TEST_DIR}$(BUILD_TEST_DIR)

run_tests: mkdir_test_build tests
	${TEST_DIR}$(BUILD_TEST_DIR)/${TEST_NAME}

coverage: run_tests
	gcovr -r . 	--exclude="third_party/doctest.h" \
				--exclude="src/res/GerenciaContaExcp.cpp" \
            	--exclude="src/res/CarteiraExcp.cpp" \
            	--exclude="src/res/TransacaoExcp.cpp" \
            	--exclude="src/res/CartaoDeCreditoExcp.cpp" \
            	--exclude="src/res/Utils.cpp" \
            	--exclude="src/res/ValidarEntrada.cpp" \
            	--exclude="src/main.cpp" \

valgrind:
	valgrind --leak-check=full $(BUILD_DIR)/$(NAME)

doc: clean_doc doc
	doxygen Doxyfile

html_coverage: run_tests
	mkdir -p ${COVERAGE_DIR}
	gcovr -r .	--exclude="third_party/doctest.h" \
            	--exclude="src/res/GerenciaContaExcp.cpp" \
            	--exclude="src/res/CarteiraExcp.cpp" \
            	--exclude="src/res/TransacaoExcp.cpp" \
            	--exclude="src/res/CartaoDeCreditoExcp.cpp" \
            	--exclude="src/res/Utils.cpp" \
            	--exclude="src/res/ValidarEntrada.cpp" \
            	--exclude="src/main.cpp" \
            	--html --html-details -o ${COVERAGE_DIR}/relatorio.html

clean_doc:
	rm -rf $(DOC_DIR)/html
	rm -rf $(DOC_DIR)/latex

clean_build:
	rm -f $(BUILD_DIR)/*.o
	rm -f $(BUILD_DIR)/*.gcda
	rm -f $(BUILD_DIR)/*.gcno
	rm -f $(BUILD_DIR)/$(NAME)

clean_tests:
	rm -rf $(TEST_DIR)$(BUILD_TEST_DIR)

clean_coverage:
	rm -rf $(COVERAGE_DIR)

clean: clean_build clean_tests clean_coverage clean_doc
