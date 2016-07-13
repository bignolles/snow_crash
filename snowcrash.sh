#!/bin/sh

export BASE_DIR=$(dirname "$0")
export KEY_PATH="$BASE_DIR/.key"
export VM_PATH="$BASE_DIR/.snowcrash_ip"

updateUser() {
	if [ ! -z "$1" ]
	then
		printf "user_id: %s\nuser_pass: %s\n" $1 `cat "./$1/.pass"` > "$KEY_PATH"
	else
		printf "updating user impossible : missing information!\n" 1>&2
		exit 1
	fi
}

updateVm() {
	if [ ! -z "$1" ] && [ ! -z "$2" ]
	then
		printf "vm_ip: %s\nvm_port: %s\n" $1 $2 > "$VM_PATH"
	else
		printf "updating vm impossible : missing information!\n" 1>&2
	fi
}

getUserId()
{
	user_id=`cat $KEY_PATH | grep user_id | sed 's/user_id: //' | tr -d "\n"`
	user_pass=`cat $KEY_PATH | grep user_pass | sed 's/user_pass: //' | tr -d "\n"`
}

getVmId()
{
	vm_ip=`cat $VM_PATH | grep vm_ip | sed 's/vm_ip: //' | tr -d "\n"`
	vm_port=`cat $VM_PATH | grep vm_port | sed 's/vm_port: //' | tr -d "\n"`
}

whoAmI()
{
	getUserId
	printf "%s\n" $user_id
	exit 0
}

whatVM()
{
	getVmId
	printf "%s:%s\n" $vm_ip $vm_port
	exit 0
}

noConnect()
{
	getUserId
	getVmId
	printf "ssh %s@%s -p %s" $user_id $vm_ip $vm_port
	exit 0
}

if [ $# -ge 1 ]
then
	argsArray=( "$@" )
	for i in `seq ${#argsArray[@]}`
	do
		elem=${argsArray[i - 1]}
		if [ "$elem" == "--update-user" ]
		then
			updateUser ${argsArray[i]}
		elif [ "$elem" == "--update-vm" ]
		then
			updateVm ${argsArray[i]} ${argsArray[i + 1]}
		elif [ "$elem" == "--whoami" ]
		then
			whoAmI
		elif [ "$elem" == "--whatvm" ]
		then
			whatVM
		elif [ "$elem" == "--no-connect" ]
		then
			noConnect
		fi
	done
fi

getUserId
getVmId
echo "$user_pass" | pbcopy
ssh $user_id@$vm_ip -p $vm_port
