echo 0 > input/tolerance
echo 0 > repr
COUNTER=0
until [ $COUNTER -gt 99 ]; do
    bin/main f f >> repr
    let COUNTER+=1
done

echo 0.02 > input/tolerance
echo 0.02 >> repr
COUNTER=0
until [ $COUNTER -gt 99 ]; do
    bin/main f f >> repr
    let COUNTER+=1
done

echo 0.04 > input/tolerance
echo 0.04 >> repr
COUNTER=0
until [ $COUNTER -gt 99 ]; do
    bin/main f f >> repr
    let COUNTER+=1
done

echo 0.06 > input/tolerance
echo 0.06 >> repr
COUNTER=0
until [ $COUNTER -gt 99 ]; do
    bin/main f f >> repr
    let COUNTER+=1
done

echo 0.08 > input/tolerance
echo 0.08 >> repr
COUNTER=0
until [ $COUNTER -gt 99 ]; do
    bin/main f f >> repr
    let COUNTER+=1
done

echo 0.1 > input/tolerance
echo 0.1 >> repr
COUNTER=0
until [ $COUNTER -gt 99 ]; do
    bin/main f f >> repr
    let COUNTER+=1
done
