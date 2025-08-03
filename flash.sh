mount_point="/mnt"

echo "Unplug and plug in Wheatboard with BOOTSEL held"
while ! blkid -L "RPI-RP2" &> /dev/null; do
    :
done

echo "Wheatboard detected!"
mount -L "RPI-RP2" "$mount_point"

if [ $? -eq 0 ]; then
    echo "Mounted Wheatboard to $mount_point"
else
    echo "Failed to mount Wheatboard"
    return -1
fi

cp $1 $mount_point
umount $mount_point
