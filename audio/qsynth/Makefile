# Created by: lazyklimm <lazyklimm@gmail.com>
# $FreeBSD$

PORTNAME=	qsynth
DISTVERSIONPREFIX=	qsynth_
DISTVERSION=	0_5_0
PORTREVISION=	1
CATEGORIES=	audio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt fluidsynth front-end application

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth

USES=		autoreconf gmake pkgconfig
USE_CXXSTD=	c++11
USE_QT5=	core gui widgets x11extras buildtools_build linguisttools_build qmake_build
USE_GL=		gl
USE_GITHUB=	yes
GH_ACCOUNT=	rncbc

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_path_ac_cv_qmake=${QMAKE} \
		ac_cv_path_ac_moc=${MOC} \
		ac_cv_path_ac_uic=${UIC} \
		ac_cv_path_ac_lupdate=${LUPDATE} \
		ac_cv_path_ac_lrelease=${LRELEASE}
CONFIGURE_ARGS=	--localedir=${DATADIR} \
		--with-fluidsynth=${LOCALBASE}

OPTIONS_DEFINE=	GRADIENT SYSTEM_TRAY XUNIQUE
OPTIONS_DEFAULT=	GRADIENT SYSTEM_TRAY XUNIQUE

GRADIENT_DESC=	Gradient eye-candy
SYSTEM_TRAY_DESC=	System-tray icon support
XUNIQUE_DESC=	X11 unique/single instance

GRADIENT_CONFIGURE_ENABLE=	gradient
SYSTEM_TRAY_CONFIGURE_ENABLE=	system-tray
XUNIQUE_CONFIGURE_ENABLE=	xunique
XUNIQUE_USE=	XORG=x11

post-patch:
	@${REINPLACE_CMD} -e ' \
		s|oss,alsa,alsa_seq,|jack,oss,|; \
		s|alsa,jack,oss,dsound,|jack,oss,dsound,|; \
		s|"/MidiDriver", "alsa_seq"|"/MidiDriver", "jack"|; \
		s|m_settings.value("/SoundFontDir").toString();|m_settings.value("/SoundFontDir").toString().isEmpty() ? "${LOCALBASE}/share/sounds/sf2" : m_settings.value("/SoundFontDir").toString();|' \
		${WRKSRC}/src/qsynthOptions.cpp

post-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} -o qsynth.mak \
		${QMAKE_ARGS})

.include <bsd.port.mk>
