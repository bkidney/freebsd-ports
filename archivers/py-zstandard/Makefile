# $FreeBSD$

PORTNAME=	zstandard
DISTVERSION=	0.9.1
CATEGORIES=	archivers python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Zstandard bindings for Python, a full-featured version

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cffi>=1.8.0:devel/py-cffi@${FLAVOR}
LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		localbase python
USE_PYTHON=	distutils autoplist
PYDISTUTILS_BUILDARGS=	--system-zstd

post-install:
	@cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR} && ${STRIP_CMD} zstd.so _zstd_cffi.so

.include <bsd.port.mk>
