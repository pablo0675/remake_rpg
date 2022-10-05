## ===========================================================
## ===========================[VAR]===========================
## ===========================================================

NAME_TEST		=			./unit_tests

NAME_GAME 		= 			miaourpg

NAME_DEBUG		=			$(NAME_GAME).debug

NAME_LIB		=			lib/libmy.a

CC 				?= 			gcc

## ===========================================================
## ==========================[PATHS]==========================
## ===========================================================

SRC_PATH		=			src/

MENU_PATH		=			$(SRC_PATH)menu/

GAME_PATH		=			$(SRC_PATH)game/

MAP_PATH		=			$(GAME_PATH)map/

CHAR_PATH		=			$(GAME_PATH)character/

ENEMY_PATH		=			$(GAME_PATH)enemy/

FIGHT_PATH		=			$(GAME_PATH)fight/

INVENTORY_PATH	=			$(GAME_PATH)inventory/

CSFML_PATH		=			$(SRC_PATH)csfml_lib/


## ===========================================================
## ===========================[SRC]===========================
## ===========================================================

SRC_MENU		=			$(MENU_PATH)menu.c

SRC_GAME		=			$(GAME_PATH)game.c

SRC_MAP			=			$(MAP_PATH)map.c

SRC_CHAR		=			$(CHAR_PATH)character.c

SRC_ENEMY		=			$(ENEMY_PATH)enemy.c

SRC_FIGHT		=			$(FIGHT_PATH)fight.c

SRC_INVENTORY	=			$(INVENTORY_PATH)inventory.c

SRC_CSFML		=			$(CSFML_PATH)window.c

SRC				=			$(SRC_PATH)main.c	\
							$(SRC_MENU)			\
							$(SRC_GAME)			\
							$(SRC_MAP)			\
							$(SRC_CHAR)			\
							$(SRC_ENEMY)		\
							$(SRC_FIGHT)		\
							$(SRC_INVENTORY)	\
							$(SRC_CSFML)

TEST_SRC		=			test_menu.c			\
							test_game.c			\

## ===========================[OBJ]===========================

GAME_OBJ        = 	$(SRC:%.c=obj/build/%.o)

DEBUG_OBJ		=	$(SRC:%.c=obj/debug/%.o)

TEST_OBJ		=	$(TEST_SRC:%.c=obj/tests/%.o) $(SRC:%.c=obj/build/%.o)

## =========================[OPTIONS]=========================

CFLAGS			=			-Wall -Wextra -O1	\

CPPFLAGS		=			-iquote includes

CSFML_FLAGS		=			-lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

LDFLAGS			=			-L lib

LDLIBS			=			-lrpgmy

LDFLAGSTEST		=			-lcriterion --coverage

## ===========================================================
## ==========================[RULES]==========================
## ===========================================================

all:	$(NAME_LIB) $(NAME_GAME)

obj/build/%.o:	./%.c
	@mkdir -p $(@D)
	$(CC) -o $@ $< -c $(CPPFLAGS) $(CFLAGS)

obj/debug/%.o:	./%.c
	@mkdir -p $(@D)
	$(CC) -o $@ $< -c $(CPPFLAGS) $(CFLAGS) --coverage

obj/tests/%.o:	tests/%.c
	@mkdir -p $(@D)
	$(CC) -o $@ $< -c $(CPPFLAGS) $(CFLAGS)

$(NAME_GAME):	$(GAME_OBJ)
	@mkdir -p $(@D)
	$(CC) -o $(NAME_GAME) $(GAME_OBJ) $(LDFLAGS) $(LDLIBS) $(CPPFLAGS) $(CSFML_FLAGS)

$(NAME_LIB):
	$(MAKE) -C lib/

re:	fclean all

clean:
	$(RM) -r obj/

fclean:	clean
	$(RM) $(NAME_GAME) *.gcda *.gcno

debug:	CFLAGS += -g
debug:	$(DEBUG_OBJ)

$(NAME_TEST):	$(OBJ_TEST)
	$(CC) -o $(NAME_TEST) $(OBJ_TEST) $(LDFLAGS) $(LDLIBS) $(LDFLAGSTEST) $(CSFML_FLAGS)

tests_run:	$(NAME_TEST)
		./$(NAME_TEST) || true

## ===========================[END]===========================

.PHONY:	all re clean fclean debug tests_run
