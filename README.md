<h1 align="center"> Philosophers </h1>
<h4 align="center"> I never thought philosophy would be so deadly </h4>

---

<h2 id="description_id"> Description of the project: </h2>

The goal of this project is to solve the classic problem of the philosophers. There are *n* philosophers around a table, a fork beetween each philosophers and a bowl of spaghetti in the middle.
For example if there is one philosopher, there is only one fork, and 3 if there are 3 philosophers.

Each has a time to eat, to sleep and must eat before starving. To eat they need both forks and when they done eating they must sleep.

---

<h2 id="usage_id"> Usage: </h2>

#### Compilation: (in the folder that contain the makefile)
```shell
make
```

How to run it:
```shell
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat_optionnal]
```
Where:
- *number_of_philosophers*: The number of philosophers and also the number of forks.
- *time_to_die* (in milliseconds): If a philosopher didn’t start eating *time_to_die ms* since the beginning of their last meal or the beginning of the simulation, they die.
- *time_to_eat* (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
- *time_to_sleep* (in milliseconds): The time a philosopher will spend sleeping.
- *number_of_times_each_philosopher_must_eat* (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.


---

<h2 id="test_id"> Test: </h2>

Execute it:
```shell
bash test.sh
```
with the arguments:
- ```no argument```: help
- ```parse value1 wrong_value```: test parsing with differents value + test leaks
- ```one time_to_die```: test with 1 philo + test leaks
- ```fsanitize time_die time_eat time_sleep nb_to_eat_optional```: launch program with custom values and fsanitize threads checking
- ```valgrind time_die time_eat time_sleep nb_to_eat_optional```: launch program with custom values and leaks check
- ```helgrind time_die time_eat time_sleep nb_to_eat_optional```: launch program with custom values and data races or deadlock check
- ```drd time_die time_eat time_sleep nb_to_eat_optional```: launch program with custom values and data races or deadlock check


