red=$(tput setaf 1)
blue=$(tput setaf 4)
magenta=$(tput setaf 5)
normal=$(tput sgr0)

if [ $# = 0 ]
then
	printf "${magenta}CMD${normal}\n"
	printf "parse + random nb test + random char/string test - Parsing Error\n"
	printf "one + time die - Test with One Philo\n"
	printf "fsanitize + time_die + time_eat + time_sleep + nb_to_eat (optional)\n"
	printf "valgrind + time_die + time_eat + time_sleep + nb_to_eat (optional)\n"
	printf "helgrind + time_die + time_eat + time_sleep + nb_to_eat (optional)\n"
	printf "drd + time_die + time_eat + time_sleep + nb_to_eat (optional)\n"
else
	if [ $1 = "parse" ] && [ $# = 3 ]
	then
		make re
		clear
		printf "${red}Error Arg${normal}\n"
		printf "${blue}<\n${normal}"
		./philo 2
		printf "${blue}>\n${normal}"
		./philo 2 100 100 100 2 13
		printf "${blue}valgrind <\n${normal}"
		valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./philo 2
		printf "${blue}valgrind >${normal}\n"
		valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./philo 2 100 100 100 2 13
		printf "\n"

		printf "${red}0 nb philo || 0 nb to eat${normal}\n"
		printf "|"
		./philo 0 100 100 100
		printf "|\n|"
		./philo 2 100 100 100 0
		printf "|\n${blue}valgrind 0 nb Philo\n${normal}"
		valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./philo 0 100 100 100
		printf "${blue}valgrind 0 nb to eat${normal}\n"
		valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./philo 2 100 100 100 0
		printf "\n"

		printf "${red}Error Arg Nb of Philo${normal}\n"
		printf "${blue}< 0${normal}\n"
		./philo -1 100 100 100
		printf "${blue}> 200${normal}\n"
		./philo 201 100 100 100
		printf "${blue}char/string/empty${normal}\n"
		./philo $3 100 100 100
		printf "${blue}valgrind < 0 / > 201\n${normal}"
		valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./philo -1 100 100 100
		printf "${blue}valgrind char/string/empty${normal}\n"
		valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./philo $3 100 100 100
		printf "\n"


		printf "\n${red}Error Arg Time Die${normal}\n"
		printf "${blue}< 60${normal}\n"
		./philo 2 $2 100 100
		printf "${blue}char/string/empty${normal}\n"
		./philo 2 $3 100 100
		printf "${blue}valgrind < 60\n${normal}"
		valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./philo 2 $2 100 100
		printf "${blue}valgrind char/string/empty${normal}\n"
		valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./philo 2 $3 100 100
		printf "\n"

		printf "\n${red}Error Arg Time Eat${normal}\n"
		printf "${blue}< 60${normal}\n"
		./philo 2 100 $2 100
		printf "${blue}char/string/empty${normal}\n"
		./philo 2 100 $3 100
		printf "${blue}valgrind < 60\n${normal}"
		valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./philo 2 100 $2 100
		printf "${blue}valgrind char/string/empty${normal}\n"
		valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./philo 2 100 $3 100
		printf "\n"


		printf "\n${red}Error Arg Time Sleep${normal}\n"
		printf "${blue}< 60${normal}\n"
		./philo 2 100 100 $2
		printf "${blue}char/string/empty${normal}\n"
		./philo 2 100 100 $3
		printf "${blue}valgrind < 60\n${normal}"
		valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./philo 2 100 100 $2
		printf "${blue}valgrind char/string/empty${normal}\n"
		valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./philo 2 100 100 $3
		printf "\n"

		printf "\n${red}Error Arg Time Nb to eat${normal}\n"
		printf "${blue}< 0${normal}\n"
		./philo 2 100 100 100 -1
		printf "${blue}char/string/empty${normal}\n"
		./philo 2 100 100 100 $3
		printf "${blue}valgrind < 0\n${normal}"
		valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./philo 2 100 100 100 -1
		printf "${blue}valgrind char/string/empty${normal}\n"
		valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./philo 2 100 100 100 $3
		printf "\n"

	elif [ $1 = "one" ] && [ $# = 2 ]
	then
		make re
		clear
		printf "${red}One philo${normal}\n"
		./philo 1 $2 100 100
		printf "${blue}valgrind${normal}\n"
		valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./philo 1 $2 100 100
	elif [ $1 = fsanitize ]
	then
		make philo_s
		clear
		./philo $2 $3 $4 $5 $6
	elif [ $1 = valgrind ]
	then
		make re
		clear
		valgrind --track-origins=yes --leak-check=full --show-leak-kinds=all ./philo $2 $3 $4 $5 $6
	elif [ $1 = helgrind ]
	then
		make re
		clear
		valgrind --tool=helgrind ./philo $2 $3 $4 $5 $6
	elif [ $1 = drd ]
	then
		make re
		clear
		valgrind --tool=drd ./philo $2 $3 $4 $5 $6
	fi
fi
