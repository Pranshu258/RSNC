COUNTER=100
until [  $COUNTER -gt 102400 ]; do
    echo $COUNTER > input/samples
    bin/main f t
    let COUNTER*=2
done
