--- content/public/common/content_switches.cc.orig	2017-04-19 19:06:34 UTC
+++ content/public/common/content_switches.cc
@@ -1006,7 +1006,7 @@ const char kDisableVaapiAcceleratedVideo
     "disable-vaapi-accelerated-video-encode";
 #endif
 
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_FREEBSD)
 // Allows sending text-to-speech requests to speech-dispatcher, a common
 // Linux speech service. Because it's buggy, the user must explicitly
 // enable it so that visiting a random webpage can't cause instability.
