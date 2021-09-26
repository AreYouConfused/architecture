 #!/bin/bash

 inputs=$(cat "as2testdata")

 counter=0
 for i in ${inputs[@]} ; do :
	if [ $counter -eq 0 ]; then 
		echo $i > temp
		counter=1
	else
		echo $i >> temp
		./floatadder < temp >> od
		counter=0
	fi
done 

rm temp
