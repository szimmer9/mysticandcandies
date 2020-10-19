#/bin/bash

I=100000
J=3

while [ $I != 0 ]; do
	 let J=J+3

    while [ $J != 0 ] do

        python generateinput.py $I > inputfiles2/inputfile-$I-$J
        let J=J-1

    done

    let I=I-500
done

for i in inputfiles2/* 
  do
  # Program will print "n $N" and timing info
  echo "running with $i"
  ./mystic $i >> outputdata2/outputdata_pq.txt
done

cat outputdata2/outputdata_pq.txt | sort -n -k 2 | awk '{printf "%d %f\n", $2, $4/(1000)}' > outputdata2/outputdata_pq_good.txt

