# $FreeBSD$

PORTNAME=	django-widget-tweaks
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rozhuk.im@gmail.com
COMMENT=	Tweak form field rendering in templates, not in python-level form definitions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>1.2:www/py-django111@${FLAVOR}

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist distutils

.include <bsd.port.mk>
