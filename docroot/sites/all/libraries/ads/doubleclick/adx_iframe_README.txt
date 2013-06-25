Google automatically detects possible expanding directions for ad slots on publisher pages and filters out non-matching expandable creatives on each ad request. 

For example, a 728x90 ad slot at the top of the page will most likely allow DOWN expansion only. A creative expanding UP won’t be allowed to serve to this ad slot. 

Automatic detection for ADI slots (or ad calls requested from within a publisher iFrame) requires hosting a specific Ad Exchange publisher side file, adx_iframe.html, which allows Google to obtain ad slot position for iframe slots. 

Configuration requirements: 

AdX Expandables Ads Iframe Buster - Required directory: 

http://www.domain.com/doubleclick/adx_iframe.html
