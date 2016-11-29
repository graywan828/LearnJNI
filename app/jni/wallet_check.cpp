#include <jni.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <android/log.h>
#include "wallet_check.h"
//生产环境
//#define PRODECT_KEY "3082036d30820255a0030201020204250877dd300d06092a864886f70d01010b05003066310b300906035504061302434e3111300f060355040813087368616e676861693111300f060355040713087368616e67686169310f300d060355040a13067368656e6d61310f300d060355040b13067368656e6d61310f300d060355040313067368656e6d613020170d3135313031393032353733365a180f32313135303932353032353733365a3066310b300906035504061302434e3111300f060355040813087368616e676861693111300f060355040713087368616e67686169310f300d060355040a13067368656e6d61310f300d060355040b13067368656e6d61310f300d060355040313067368656e6d6130820122300d06092a864886f70d01010105000382010f003082010a0282010100afdfa38b8ce7f261fe1c2f18d52e106c2bae6afa0feff8cd746f72e92dfefd66f042959d17dd6a0b7ff4cb86d9a4cdb7ee72cd8c9ae3649c4e18669424a4325c01ef1844c4f548c38ed8dc752dd4635141351712702e3b12a2a7dce6c0d26872008d2ae6188559f5c1198e35eb00ec7aeece47a70fff4bb5fca99ec1a54b2d5ef6c979f7550ce69ed0f640c768d19e7ed10a308ac01058f143eb65e6cc3fecf9c8af369483d8003fab76680779b12d4c4a07abd7a99f6501e9d98fe545e6fb04c271e56a7aaa60c6f82dd0fed8c6cabf8591a4646526da8d9a23e96677edad5beaa97780cb204967906e172c660e2386d63fff1cd13309f6faf887fdd85507570203010001a321301f301d0603551d0e0416041488a3128445f18dc31d1d88d4b515e600a553fbaf300d06092a864886f70d01010b050003820101009d72e00a840d3acdd1500ab3b5271bcd44088b8315d8c4fa32fafed96f82e7b5299073aed91340e63006f32459bd67cfeb8101762d394da7f64cc63aacce6d5becd18120eff8ab4768a96789febafdfbaf9a5f78595d44f7c8d0905ac08abcacc27bb29555d2671174a6af5f506eaebc6e220c7fdfc6e729d89510a92ed9156af5bb390b9890ce1a7e0917ede156b79444bb9ce283312f00b66724f0401396198369e52bbd809ef81777e0db96f6d6333f83eee1f968f891e926aa338b907c00b8df17b3fb060e947b35abbaaedebd643be730e4eab3e52a31ad4beb757857c000c7e0defcb0c1086764725ea255830436d2feb98e2476471c75cf3c883f99f7"
//自己的keystore
#define PRODECT_KEY "3082030d308201f5a003020102020428a1ff34300d06092a864886f70d01010b05003037310b30090603550406130255533110300e060355040a1307416e64726f6964311630140603550403130d416e64726f6964204465627567301e170d3136303332313037343130325a170d3436303331343037343130325a3037310b30090603550406130255533110300e060355040a1307416e64726f6964311630140603550403130d416e64726f696420446562756730820122300d06092a864886f70d01010105000382010f003082010a0282010100dbaa83a10e9327b8cc4f89a7743fd3f57f0f02c49d22839fd4a1be225b5567d18d9db4a66ae38cdfea8717344689c49d4242263f22e76fdcc566a51dc005c318f2db7755788b2d07825f5c6354a51cd99f12de63ea757642c258d4a92712ff0c1d6398385fd5f219e98e51c7451f73157b0005fc538b2c5b548b9338e2df816800547bacb5edb208da05ba3b4c7a02314b58ff2a1705af2e54160275dac4bd9328f2b1c170ce780b317c41a9d39c9434d53dd41e0c8dacf6ddb694852283d2c56a240a495c7aaa20053b6e88bfbd9ff49e0ed68702324bd28c6f57d81da0808bb274d91fc347f4d73b2ff7dc446811ecead543bffb6b55c74c66c91e212954010203010001a321301f301d0603551d0e041604148ddc5ff6cfb6a018e4065796d8e4c0c1a0ed0fae300d06092a864886f70d01010b05000382010100c8aee83a14f540a6059432323ca4b0bede3ecda5db543a59d220beda4187ee9936e78e7cca5225e1724e44c645575690f0b96d291c47a92d6fe5c81490018f8ed01d408a0859f8757aa6c76736f9ab73c7f8d752cd391175f00cdd9330adf9146db0a5821da5880f5edef8f509dd6160584f1c49459199da5dec1607774004db536f9ecafde2d4ce6db01d2a8c6406fa1e3140783bfe2e4a2b110464def18ac7402c90b334a2713b36516581493243cd3cc9af833085077431fbdfdfa9449e2db149e55f2950259a86d2d785bf4aedf56ba4378c451af346de5e7317bac450dd6a91f750fde342bddc9871c256dbf2ff22c7a3b815892dc135530bfef8bd8f2f"

jstring JNICALL Java_com_wochacha_learnjni_utils_JNIUtils_get3DESKey(
		JNIEnv *env, jclass clazz, jobject thiz) {
	jstring ori =env->NewStringUTF(PRODECT_KEY);

	jstring str = getSignature(env, thiz);
	if (equals(env,str, ori)) {
		return env->NewStringUTF("SHHBJR$mobile%0519[!SECRET@]&");
	} else {
		return env->NewStringUTF("");
	}
}

jstring JNICALL Java_com_wochacha_learnjni_utils_JNIUtils_Add(
		JNIEnv *env, jclass clazz, jobject thiz) {

	jstring ori =env->NewStringUTF(PRODECT_KEY);

	jstring str = getSignature(env, thiz);
	if (equals(env,str, ori)) {
		return env->NewStringUTF("20150519");
	} else {
		return env->NewStringUTF("");
	}

}

jboolean equals(JNIEnv *env,jstring str, jstring ori) {
	jclass cls = env->FindClass("java/lang/String");
	jmethodID methodId = env->GetMethodID(cls, "equals",
			"(Ljava/lang/Object;)Z");
	return env->CallBooleanMethod(str, methodId, ori);
}

jstring getSignature(JNIEnv* env, jobject thiz) {
//   context
	jclass native_context = env->GetObjectClass(thiz);

// context.getPackageManager()
	jmethodID methodID_func = env->GetMethodID(native_context,
			"getPackageManager", "()Landroid/content/pm/PackageManager;");
	jobject package_manager = env->CallObjectMethod(thiz, methodID_func);
	jclass pm_clazz = env->GetObjectClass(package_manager);

//packageManager.getPackageInfo()
	jmethodID methodId_pm = env->GetMethodID(pm_clazz, "getPackageInfo",
			"(Ljava/lang/String;I)Landroid/content/pm/PackageInfo;");

//context.getPackageName()
	jmethodID methodID_packagename = env->GetMethodID(native_context,
			"getPackageName", "()Ljava/lang/String;");
	jstring name_str = static_cast<jstring>(env->CallObjectMethod(thiz,
			methodID_packagename));
	jobject package_info = env->CallObjectMethod(package_manager, methodId_pm,
			name_str, 64);
	jclass pi_clazz = env->GetObjectClass(package_info);

//packageInfo.signatures
	jfieldID fieldID_signatures = env->GetFieldID(pi_clazz, "signatures",
			"[Landroid/content/pm/Signature;");
	jobject signatur = env->GetObjectField(package_info, fieldID_signatures);
	jobjectArray signatures = reinterpret_cast<jobjectArray>(signatur);

//signatures[0]
	jobject signature = env->GetObjectArrayElement(signatures, 0);
	jclass s_clazz = env->GetObjectClass(signature);

//signatures[0].toCharString()
	jmethodID methodId_ts = env->GetMethodID(s_clazz, "toCharsString",
			"()Ljava/lang/String;");
	jobject ts = env->CallObjectMethod(signature, methodId_ts);

//return signature
	return reinterpret_cast<jstring>(ts);
}
