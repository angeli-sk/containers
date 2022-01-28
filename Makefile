# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: akramp <akramp@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/01/20 15:59:53 by akramp        #+#    #+#                  #
#    Updated: 2022/01/27 13:40:27 by akramp        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = containers
CC = clang++
FLAGS = -Wall -Werror -Wextra -std=c++98

#✧･ﾟ: *✧･ﾟ:*  *:･ﾟ✧*:･ﾟ✧✧･ *✧･ﾟ:* SOURCES ✧*:･ﾟ✧: *✧･ﾟ:*  *:･ﾟ✧*:･ﾟ✧✧･ﾟ: *✧･ﾟ:#

SRC = 	containers.cpp vector.cpp

#✧･ﾟ: *✧･ﾟ:*  *:･ﾟ✧*:･ﾟ✧✧･ *✧･ﾟ:* COLORS ✧*:･ﾟ✧: *✧･ﾟ:* ✧ *:･ﾟ✧*:･ﾟ✧✧･ﾟ: *✧･ﾟ:#

ORANGE	= 	\033[38;5;208m
YELLOW2	= \033[38;5;221m
WHITE	= \033[38;5;230m
RED		= \033[38;5;196m
RR		= \033[38;5;160m

#✧･ﾟ: *✧･ﾟ:*  *:･ﾟ✧*:･ﾟ✧✧･ *✧･ﾟ:*  RULES  ✧*:･ﾟ✧: *✧･ﾟ:*  *:･ﾟ✧*:･ﾟ✧✧･ﾟ: *✧･ﾟ:#

all: $(NAME)

$(NAME): $(SRC)
	@$(CC) $(FLAGS) $(SRC) -o $(NAME)
	@echo "$(ORANGE)\n:۞:••:۞::۞:••:۞:••:۞:••:۞:••:۞::۞:••:"
	@echo "$(RED)🔥:۞:••:۞:ᴄᴏᴍᴘɪʟᴀᴛɪᴏɴ ᴅᴏɴᴇ!:۞:••:۞:🔥"
	@echo "$(ORANGE):۞:••:۞::۞:••:۞:••:۞:••:۞:••:۞::۞:••:"

stars:
	@echo "$(RR):۞:••:۞:••:۞:••:۞:••:۞::۞:••:۞:••:۞::"

clean:
	@echo "$(ORANGE)🌻۞:••:۞:••$(RED)Ｃｌｅａｎｉｎｇ$(ORANGE):۞:••:۞::💫$(WHITE)\n"
	rm -f ./*~ ./*# a.out $(OBJ)
	@echo "\n$(YELLOW2)✨:••:۞:•:۞:$(RED)Cleaning Done!$(YELLOW2):۞:••:۞:•:⚡$(WHITE)"

fclean: clean stars
	@echo "$(ORANGE)🌻۞:••:۞:$(RED)ʀᴇᴍᴏᴠɪɴɢ $(NAME)$(ORANGE):۞:••:۞:💫\n$(WHITE)"
	rm -f $(NAME)
	@echo "\n$(YELLOW2)✨۞:••:۞:$(RED)Removed $(NAME)!$(YELLOW2):۞:••:۞⚡$(WHITE)"

re: fclean all
