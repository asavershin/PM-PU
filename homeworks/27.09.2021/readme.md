#Описание скриптов akkerman.sh и task1.sh
## akkerman.sh


    if (( $1 == 0 ))
    then
      echo $(($2+1))
    fi
    if (( ($1>0) && ($2 == 0) ))
    then
      temp2=$(($1-1))
      result=$(akkerman $temp2 1)
      echo $result
    fi
    if (( ($1>0) && ($2>0) ))
    then
      temp3=$(($2-1))
      temp4=$(($1-1))
      temp=$(akkerman $1 $temp3)
      result=$(akkerman $temp4 $temp)
      echo $result
    fi
  
  Это участок кода из функции akkerman. Эта функция работает рекурсивно, мы с помощью echo выводим результат, 
  чтобы потом его считать и запустить новую ветку рекурсии. Первый echo $(($2+1)) по сути возвращает нам результат в поток вывода
  (это некоторое подражание return в c++), следующие echo $result работают аналогичным образом.
  
## Task1.sh

Скрипт выводит таблицу кодов ASCII от 33 до 255
