@echo off
rem
rem
rem
rem
rem
title  JNI

set current_path=%cd%
cd ..

set pro_path=%cd%

rem goto STEP_2

rem
rem compile jni && check exist
rem
:STEP_1
call %pro_path%\jni\jniBuilder.bat
if not exist %pro_path%\libs\armeabi\libChspDesigner.so goto Err_LIBERR
pause
rem
rem  package apk 
rem
:STEP_2 

call android update project -p . -t android-14
rem  ��ʼ����     
call ant clean
rem  ��ʼ���CHSP.apk
call ant release
rem  �ж�CHSP.apk��ɽ��
if not exist %pro_path%\bin\CHSP.apk goto Err_DEMOERR 
goto SUCCESS

:Err_LIBERR
echo ****************************************************************************
echo [ CHSP ] export NATIVELIBRARY ERROR!!!!
echo ****************************************************************************
goto Finish

:Err_JARERR
echo ****************************************************************************
echo [ CHSP ] export UPEntrust.jar ERROR!!!!
echo ****************************************************************************
goto Finish

:Err_DEMOERR
echo ****************************************************************************
echo [ CHSP ] export CHSP.apk ERROR!!!!
echo ****************************************************************************
goto Finish

:SUCCESS
echo ****************************************************************************
echo [ CHSP ] ����ɹ���
echo ****************************************************************************
goto Finish

:Finish
pause
