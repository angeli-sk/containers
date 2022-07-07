# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: akramp <akramp@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/20 15:59:53 by akramp        #+#    #+#                  #
#    Updated: 2022/07/07 16:25:49 by akramp        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = containers
CC = clang++
FLAGS = -Wall -Werror -Wextra -std=c++98

#✧･ﾟ: *✧･ﾟ:*  *:･ﾟ✧*:･ﾟ✧✧･ *✧･ﾟ:* SOURCES ✧*:･ﾟ✧: *✧･ﾟ:*  *:･ﾟ✧*:･ﾟ✧✧･ﾟ: *✧･ﾟ:#

SRC = 	containers.cpp

#✧･ﾟ: *✧･ﾟ:*  *:･ﾟ✧*:･ﾟ✧✧･ *✧･ﾟ:* COLORS ✧*:･ﾟ✧: *✧･ﾟ:* ✧ *:･ﾟ✧*:･ﾟ✧✧･ﾟ: *✧･ﾟ:#

ORANGE	= 	\033[38;5;208m
YELLOW2	= \033[38;5;221m
WHITE	= \033[0m
RED		= \033[38;5;196m
RR		= \033[38;5;160m

#✧･ﾟ: *✧･ﾟ:*  *:･ﾟ✧*:･ﾟ✧✧･ *✧･ﾟ:*  RULES  ✧*:･ﾟ✧: *✧･ﾟ:*  *:･ﾟ✧*:･ﾟ✧✧･ﾟ: *✧･ﾟ:#

all: $(NAME)



$(NAME): $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "\n$(ORANGE)-ˋˏ✄┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n"
	@echo "$(YELLOW2)╒════════════════ ✰° \n$(ORANGE)$(YELLOW2)│$(ORANGE) ᴄᴏᴍᴘɪʟᴀᴛɪᴏɴ ᴅᴏɴᴇ!$(YELLOW2)│$(ORANGE)\n$(YELLOW2)°✰ ════════════════╛$(WHITE)\n"

clean:
	@echo "$(YELLOW2)╭────────────.★..─╮\n$(ORANGE)$(YELLOW2)│$(ORANGE)    ᴄʟᴇᴀɴɪɴɢ...$(YELLOW2)  │$(ORANGE)     $(YELLOW2)\n╰─..★.────────────╯$(WHITE)"
	@rm -f ./*~ ./*# a.out $(OBJ)

fclean: clean
	@echo "\n$(ORANGE)-ˋˏ✄┈┈┈┈┈┈┈┈┈┈┈┈┈┈┈\n"
	@echo "$(YELLOW2) ───$(RED)♡$(ORANGE) ──────────────\n$(RED) ʀᴇᴍᴏᴠᴇᴅ $(NAME)\n$(ORANGE) ───$(RED)♡$(YELLOW2) ──────────────"
	@rm -f $(NAME)

re: fclean all
