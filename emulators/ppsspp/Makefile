# $FreeBSD$

PORTNAME=	ppsspp
DISTVERSIONPREFIX=	v
DISTVERSION?=	1.6.3
PORTREVISION?=	0
CATEGORIES=	emulators
# XXX Get from Debian once #697821 lands
MASTER_SITES=	https://bazaar.launchpad.net/~sergio-br2/${PORTNAME}/debian-sdl/download/5/${PORTNAME}.1-20140802045408-dd26dik367ztj5xg-8/:manpage
DISTFILES=	${PORTNAME}.1:manpage
EXTRACT_ONLY=	${DISTFILES:N*\:manpage:C/:.*//}

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${GH_PROJECT}/commit/
PATCHFILES=	c783e7761c2a.patch:-p1
PATCHFILES+=	f2a75719d843.patch:-p1
PATCHFILES+=	78a41980dfd7.patch:-p1

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	PSP emulator in C++ with dynarec JIT for x86, ARM, MIPS

LICENSE=	GPLv2+

LIB_DEPENDS=	libzip.so:archivers/libzip \
		libsnappy.so:archivers/snappy \
		libavcodec.so:multimedia/ffmpeg
RUN_DEPENDS=	xdg-open:devel/xdg-utils

USE_GITHUB=	yes
GH_ACCOUNT=	hrydgard
GH_TUPLE?=	hrydgard:glslang:2edde666:glslang/ext/glslang \
		hrydgard:${PORTNAME}-lang:1153a42:lang/assets/lang \
		KhronosGroup:SPIRV-Cross:90966d5:SPIRV/ext/SPIRV-Cross \
		Kingcom:armips:v0.9-89-g8b4cada:armips/ext/armips \
		Kingcom:tinyformat:Release-2.0.1-7-gb7f5a22:tinyformat/ext/armips/ext/tinyformat

CONFLICTS_INSTALL=	${PORTNAME}-*

USES=		cmake:outsource compiler:c++11-lib localbase:ldflags pkgconfig
EXCLUDE=	libzip zlib
EXTRACT_AFTER_ARGS=${EXCLUDE:S,^,--exclude ,}
USE_GL=		gl glew glu
USE_SDL=	sdl2 # joystick
CMAKE_ON=	USE_SYSTEM_FFMPEG USE_SYSTEM_LIBZIP
SUB_FILES=	pkg-message
PORTDATA=	assets ${PORTNAME}

DESKTOP_ENTRIES="PPSSPP" \
		"" \
		"${PORTNAME}" \
		"${PORTNAME} %f" \
		"Game;Emulator;" \
		""

OPTIONS_DEFINE=	OLDJOY
OPTIONS_SINGLE=	GUI
OPTIONS_SINGLE_GUI=	QT5 SDL
OPTIONS_SLAVE?=	LIBRETRO SDL
OPTIONS_EXCLUDE:=	${OPTIONS_SINGLE_GUI}

LIBRETRO_DESC=	libretro core for games/retroarch
LIBRETRO_CMAKE_BOOL=	LIBRETRO
LIBRETRO_PLIST_FILES=	lib/libretro/${PORTNAME}_libretro.so
LIBRETRO_IMPLIES=	SDL
OLDJOY_DESC=	Old joystick support with fixed button mappings (deprecated)
OLDJOY_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-old-joy
QT5_USE=	QT5=qmake_build,buildtools_build,linguisttools_build,gui,opengl,widgets
QT5_CMAKE_BOOL=	USING_QT_UI
QT5_VARS=	EXENAME=PPSSPPQt
SDL_BUILD_DEPENDS=	png>=1.6:graphics/png
SDL_LIB_DEPENDS=	libpng.so:graphics/png
SDL_VARS=	EXENAME=PPSSPPSDL

post-patch:
	@${REINPLACE_CMD} -e 's/Linux/${OPSYS}/' \
		${WRKSRC}/assets/gamecontrollerdb.txt
	@${REINPLACE_CMD} -e 's,/usr/share,${PREFIX}/share,' \
		${WRKSRC}/UI/NativeApp.cpp
	@${REINPLACE_CMD} -e 's/"unknown"/"${GH_TAGNAME}"/' \
		${WRKSRC}/git-version.cmake

do-install:
# cmake doesn't pack assets into the app unlike qmake
	(cd ${INSTALL_WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDATA:N${PORTNAME}}" ${STAGEDIR}${DATADIR})
# Install the app alongside assets to avoid warnings with GetExeDirectory()
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/${EXENAME} \
		${STAGEDIR}${DATADIR}/${PORTNAME}
	${LN} -sf ../${DATADIR_REL}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

	${INSTALL_MAN} ${_DISTDIR}/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	(cd ${WRKSRC}/icons && ${COPYTREE_SHARE} \
		"hicolor" ${STAGEDIR}${PREFIX}/share/icons)
	${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps
	${INSTALL_DATA} ${WRKSRC}/icons/icon-512.svg \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/scalable/apps/${PORTNAME}.svg

do-install-LIBRETRO-on:
	${MKDIR} ${STAGEDIR}${PREFIX}/${LIBRETRO_PLIST_FILES:H}
	${INSTALL_LIB} ${BUILD_WRKSRC}/lib/${LIBRETRO_PLIST_FILES:T} \
		${STAGEDIR}${PREFIX}/${LIBRETRO_PLIST_FILES:H}

.include <bsd.port.mk>
