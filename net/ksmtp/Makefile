# $FreeBSD$

PORTNAME=	ksmtp
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
CATEGORIES=	net kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Job-based library to send email through an SMTP server

LICENSE=	LGPL21
LIB_DEPENDS=	libsasl2.so:security/cyrus-sasl2

USES=		cmake:outsource compiler:c++11-lib gettext kde:5 tar:xz
USE_KDE=	config coreaddons i18n kio service
# pim components
USE_KDE+=	mime
USE_QT5=	core network \
		buildtools_build qmake_build

USE_LDCONFIG=	yes

.include <bsd.port.mk>
