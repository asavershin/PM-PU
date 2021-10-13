# Описание работы скриптов palindrome.sh и babbage.sh

## palindrome.sh

В скрипте происходит следующее:   
* считывается слово, введенное пользователем, в переменную line
* После записывается перевернутое это же слово в переменную enil
* Сравнивается начала до середины двух слов
* Выводится результат: палиндром введённое слово или нет
    
  
 
  
## babbage.sh

  Мы перефразировали задачу, чтобы не было перебора.   
  Пусть n наше искомое число, которое при возведении в квадрат даёт число, которое заканчивается на 269696  
  Проделаем некоторые простые выкладки:  
  n^2 - 69696 = (n-264)*(n+264) = 1000000*k + 200000 = 2^6 * 5^5* (5*k + 1)   
  Числа  n – 264  и  n + 264  не могут одновременно делиться на 5, так как их разность равна 528.    
  Следовательно, либо  n – 4,  либо  n + 4  делится на 5^5.   
  Кроме того, оба числа чётны и делятся на 8, иначе их произведение не делилось бы на 2^6.    
  Значит, хотя бы одно из этих чисел делится на  5^5*8 = 25000,  то есть  n = 25000m +- 264.      
  n = 25000*m +- 264   
  n^2 = 625 000 000*m^2 +-13 200 000*m +69696   
  