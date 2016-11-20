echo 0.1 > input/tolerance
echo 0.1 >> repr
COUNTER=0
until [ $COUNTER -gt 100 ]; do
    bin/main f f >> repr
    let COUNTER+=1
done

echo 0.2 > input/tolerance
echo 0.2 >> repr
COUNTER=0
until [ $COUNTER -gt 100 ]; do
    bin/main f f >> repr
    let COUNTER+=1
done

echo 0.3 > input/tolerance
echo 0.3 >> repr
COUNTER=0
until [ $COUNTER -gt 100 ]; do
    bin/main f f >> repr
    let COUNTER+=1
done

echo 0.4 > input/tolerance
echo 0.4 >> repr
COUNTER=0
until [ $COUNTER -gt 100 ]; do
    bin/main f f >> repr
    let COUNTER+=1
done

echo 0.5 > input/tolerance
echo 0.5 >> repr
COUNTER=0
until [ $COUNTER -gt 100 ]; do
    bin/main f f >> repr
    let COUNTER+=1
done
