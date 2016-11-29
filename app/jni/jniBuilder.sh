#!/bin/sh
export ANDROID_NDK_ROOT=$NDK_ROOT
#export MOBILE_PAY_TRUNK=$(cd "$(dirname "$0")";cd ..;cd ..; pwd)
export MOBILE_PAY_TRUNK=$(cd "$(dirname "$0")";cd ..;pwd)
#SO_NAME=libucpayplugin.so
#TRUNK_DIR=$MOBILE_PAY_TRUNK
#SO_SRC_PATH=$MOBILE_PAY_TRUNK/BrowserPlugin/obj/local/armeabi/$SO_NAME
#SO_DEST_DIR1=$TRUNK_DIR/cupsecurepay/libs/armeabi/$SO_NAME
#
#cd $MOBILE_PAY_TRUNK/BrowserPlugin

#ɾ���ʧ�Ķ�̬��
echo "clean the midlle files...."
#rm  -rf $MOBILE_PAY_TRUNK/obj
#rm  -rf $MOBILE_PAY_TRUNK/libs/armeabi/libhello.so

cd $MOBILE_PAY_TRUNK/jni
#ln -s $MOBILE_PAY_TRUNK/BrowserPlugin/browserpluginMake $ANDROID_NDK_ROOT/apps/browserpluginMake
$ANDROID_NDK_ROOT/ndk-build $1

#��̬��û����ɳɹ����˳�
if [ ! -f $SO_SRC_PATH ]
then
    echo "****************************************************************************"
    echo "   Generate libucpayplugin.so library failed!        __shell.sh             "
	echo "****************************************************************************"
else
	echo "****************************************************************************"
	echo "*    Generate libucpayplugin.so successfully          __shell.sh            "
	echo "****************************************************************************"
fi
