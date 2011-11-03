


<!DOCTYPE html>
<html>
  <head>
    <meta charset='utf-8'>
    <meta http-equiv="X-UA-Compatible" content="chrome=1">
        <title>plugin/jquery.writeCapture.js at master from iamnoah/writeCapture - GitHub</title>
    <link rel="search" type="application/opensearchdescription+xml" href="/opensearch.xml" title="GitHub" />
    <link rel="fluid-icon" href="https://github.com/fluidicon.png" title="GitHub" />

    
    

    <meta content="authenticity_token" name="csrf-param" />
<meta content="ba02115e85cac3164524c40afd061121b7405d2d" name="csrf-token" />

    <link href="https://a248.e.akamai.net/assets.github.com/stylesheets/bundle_github.css?b4b7d3dfc591909dc4259677aecf00c2b4bdd58c" media="screen" rel="stylesheet" type="text/css" />
    

    <script src="https://a248.e.akamai.net/assets.github.com/javascripts/bundle_jquery.js?1cda878e9113acce74087d5ff1a5e1c49fb94eeb" type="text/javascript"></script>
    <script src="https://a248.e.akamai.net/assets.github.com/javascripts/bundle_github.js?f85340baf697600405a21c9b45ac1a314f3ece97" type="text/javascript"></script>
    

      <link rel='permalink' href='/iamnoah/writeCapture/blob/6cbce2274c8d035a6bb6534b510299b2af32d1d7/plugin/jquery.writeCapture.js'>
    

    <meta name="description" content="writeCapture - Utility to assist the Ajax loading of HTML containing script tags that use document.write. Mailing List: http://groups.google.com/group/writecapturejs-users" />
  <link href="https://github.com/iamnoah/writeCapture/commits/master.atom" rel="alternate" title="Recent Commits to writeCapture:master" type="application/atom+xml" />

  </head>


  <body class="logged_out page-blob linux env-production ">
    


    

    <div id="main">
      <div id="header" class="true">
          <a class="logo" href="https://github.com">
            <img alt="github" class="default svg" height="45" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov6.svg" />
            <img alt="github" class="default png" height="45" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov6.png" />
            <!--[if (gt IE 8)|!(IE)]><!-->
            <img alt="github" class="hover svg" height="45" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov6-hover.svg" />
            <img alt="github" class="hover png" height="45" src="https://a248.e.akamai.net/assets.github.com/images/modules/header/logov6-hover.png" />
            <!--<![endif]-->
          </a>

        <div class="topsearch">
    <!--
      make sure to use fully qualified URLs here since this nav
      is used on error pages on other domains
    -->
    <ul class="nav logged_out">
        <li class="pricing"><a href="https://github.com/plans">Signup and Pricing</a></li>
        <li class="explore"><a href="https://github.com/explore">Explore GitHub</a></li>
      <li class="features"><a href="https://github.com/features">Features</a></li>
        <li class="blog"><a href="https://github.com/blog">Blog</a></li>
      <li class="login"><a href="https://github.com/login?return_to=%2Fiamnoah%2FwriteCapture%2Fblob%2Fmaster%2Fplugin%2Fjquery.writeCapture.js">Login</a></li>
    </ul>
</div>

      </div>

      
            <div class="site">
      <div class="pagehead repohead vis-public   instapaper_ignore readability-menu">


      <div class="title-actions-bar">
        <h1>
          <a href="/iamnoah">iamnoah</a> /
          <strong><a href="/iamnoah/writeCapture" class="js-current-repository">writeCapture</a></strong>
        </h1>
        



            <ul class="pagehead-actions">

        <li>
            <a href="/iamnoah/writeCapture/toggle_watch" class="minibutton btn-watch watch-button" data-method="post"><span><span class="icon"></span>Watch</span></a>
        </li>
            <li><a href="/iamnoah/writeCapture/fork" class="minibutton btn-fork fork-button" data-method="post"><span><span class="icon"></span>Fork</span></a></li>

      <li class="repostats">
        <ul class="repo-stats">
          <li class="watchers ">
            <a href="/iamnoah/writeCapture/watchers" title="Watchers" class="tooltipped downwards">
              96
            </a>
          </li>
          <li class="forks">
            <a href="/iamnoah/writeCapture/network" title="Forks" class="tooltipped downwards">
              13
            </a>
          </li>
        </ul>
      </li>
    </ul>

      </div>

        

  <ul class="tabs">
    <li><a href="/iamnoah/writeCapture" class="selected" highlight="repo_sourcerepo_downloadsrepo_commitsrepo_tagsrepo_branches">Code</a></li>
    <li><a href="/iamnoah/writeCapture/network" highlight="repo_networkrepo_fork_queue">Network</a>
    <li><a href="/iamnoah/writeCapture/pulls" highlight="repo_pulls">Pull Requests <span class='counter'>0</span></a></li>

      <li><a href="/iamnoah/writeCapture/issues" highlight="repo_issues">Issues <span class='counter'>1</span></a></li>

      <li><a href="/iamnoah/writeCapture/wiki" highlight="repo_wiki">Wiki <span class='counter'>5</span></a></li>

    <li><a href="/iamnoah/writeCapture/graphs" highlight="repo_graphsrepo_contributors">Stats &amp; Graphs</a></li>

  </ul>

  
<div class="frame frame-center tree-finder" style="display:none"
      data-tree-list-url="/iamnoah/writeCapture/tree-list/6cbce2274c8d035a6bb6534b510299b2af32d1d7"
      data-blob-url-prefix="/iamnoah/writeCapture/blob/6cbce2274c8d035a6bb6534b510299b2af32d1d7"
    >

  <div class="breadcrumb">
    <b><a href="/iamnoah/writeCapture">writeCapture</a></b> /
    <input class="tree-finder-input" type="text" name="query" autocomplete="off" spellcheck="false">
  </div>

    <div class="octotip">
      <p>
        <a href="/iamnoah/writeCapture/dismiss-tree-finder-help" class="dismiss js-dismiss-tree-list-help" title="Hide this notice forever">Dismiss</a>
        <strong>Octotip:</strong> You've activated the <em>file finder</em>
        by pressing <span class="kbd">t</span> Start typing to filter the
        file list. Use <span class="kbd badmono">↑</span> and
        <span class="kbd badmono">↓</span> to navigate,
        <span class="kbd">enter</span> to view files.
      </p>
    </div>

  <table class="tree-browser" cellpadding="0" cellspacing="0">
    <tr class="js-header"><th>&nbsp;</th><th>name</th></tr>
    <tr class="js-no-results no-results" style="display: none">
      <th colspan="2">No matching files</th>
    </tr>
    <tbody class="js-results-list">
    </tbody>
  </table>
</div>

<div id="jump-to-line" style="display:none">
  <h2>Jump to Line</h2>
  <form>
    <input class="textfield" type="text">
    <div class="full-button">
      <button type="submit" class="classy">
        <span>Go</span>
      </button>
    </div>
  </form>
</div>


<div class="subnav-bar">

  <ul class="actions">
    
      <li class="switcher">

        <div class="context-menu-container js-menu-container">
          <span class="text">Current branch:</span>
          <a href="#"
             class="minibutton bigger switcher context-menu-button js-menu-target js-commitish-button btn-branch repo-tree"
             data-master-branch="master"
             data-ref="master">
            <span><span class="icon"></span>master</span>
          </a>

          <div class="context-pane commitish-context js-menu-content">
            <a href="javascript:;" class="close js-menu-close"></a>
            <div class="title">Switch Branches/Tags</div>
            <div class="body pane-selector commitish-selector js-filterable-commitishes">
              <div class="filterbar">
                <div class="placeholder-field js-placeholder-field">
                  <label class="placeholder" for="context-commitish-filter-field" data-placeholder-mode="sticky">Filter branches/tags</label>
                  <input type="text" id="context-commitish-filter-field" class="commitish-filter" />
                </div>

                <ul class="tabs">
                  <li><a href="#" data-filter="branches" class="selected">Branches</a></li>
                  <li><a href="#" data-filter="tags">Tags</a></li>
                </ul>
              </div>

                <div class="commitish-item branch-commitish selector-item">
                  <h4>
                      <a href="/iamnoah/writeCapture/blob/evalInPlace/plugin/jquery.writeCapture.js" data-name="evalInPlace">evalInPlace</a>
                  </h4>
                </div>
                <div class="commitish-item branch-commitish selector-item">
                  <h4>
                      <a href="/iamnoah/writeCapture/blob/getElementsByTag/plugin/jquery.writeCapture.js" data-name="getElementsByTag">getElementsByTag</a>
                  </h4>
                </div>
                <div class="commitish-item branch-commitish selector-item">
                  <h4>
                      <a href="/iamnoah/writeCapture/blob/gh-pages/plugin/jquery.writeCapture.js" data-name="gh-pages">gh-pages</a>
                  </h4>
                </div>
                <div class="commitish-item branch-commitish selector-item">
                  <h4>
                      <a href="/iamnoah/writeCapture/blob/master/plugin/jquery.writeCapture.js" data-name="master">master</a>
                  </h4>
                </div>
                <div class="commitish-item branch-commitish selector-item">
                  <h4>
                      <a href="/iamnoah/writeCapture/blob/scriptInPlace/plugin/jquery.writeCapture.js" data-name="scriptInPlace">scriptInPlace</a>
                  </h4>
                </div>

                <div class="commitish-item tag-commitish selector-item">
                  <h4>
                      <a href="/iamnoah/writeCapture/blob/v1.0.5/plugin/jquery.writeCapture.js" data-name="v1.0.5">v1.0.5</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item">
                  <h4>
                      <a href="/iamnoah/writeCapture/blob/v1.0.0/plugin/jquery.writeCapture.js" data-name="v1.0.0">v1.0.0</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item">
                  <h4>
                      <a href="/iamnoah/writeCapture/blob/v0.9.0/plugin/jquery.writeCapture.js" data-name="v0.9.0">v0.9.0</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item">
                  <h4>
                      <a href="/iamnoah/writeCapture/blob/v0.3.3/plugin/jquery.writeCapture.js" data-name="v0.3.3">v0.3.3</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item">
                  <h4>
                      <a href="/iamnoah/writeCapture/blob/v0.3.2/plugin/jquery.writeCapture.js" data-name="v0.3.2">v0.3.2</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item">
                  <h4>
                      <a href="/iamnoah/writeCapture/blob/v0.3.1/plugin/jquery.writeCapture.js" data-name="v0.3.1">v0.3.1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item">
                  <h4>
                      <a href="/iamnoah/writeCapture/blob/v0.3.0/plugin/jquery.writeCapture.js" data-name="v0.3.0">v0.3.0</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item">
                  <h4>
                      <a href="/iamnoah/writeCapture/blob/v0.2.1/plugin/jquery.writeCapture.js" data-name="v0.2.1">v0.2.1</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item">
                  <h4>
                      <a href="/iamnoah/writeCapture/blob/v0.2.0/plugin/jquery.writeCapture.js" data-name="v0.2.0">v0.2.0</a>
                  </h4>
                </div>
                <div class="commitish-item tag-commitish selector-item">
                  <h4>
                      <a href="/iamnoah/writeCapture/blob/v0.1/plugin/jquery.writeCapture.js" data-name="v0.1">v0.1</a>
                  </h4>
                </div>

              <div class="no-results" style="display:none">Nothing to show</div>
            </div>
          </div><!-- /.commitish-context-context -->
        </div>

      </li>
  </ul>

  <ul class="subnav">
    <li><a href="/iamnoah/writeCapture" class="selected" highlight="repo_source">Files</a></li>
    <li><a href="/iamnoah/writeCapture/commits/master" highlight="repo_commits">Commits</a></li>
    <li><a href="/iamnoah/writeCapture/branches" class="" highlight="repo_branches">Branches <span class="counter">5</span></a></li>
    <li><a href="/iamnoah/writeCapture/tags" class="" highlight="repo_tags">Tags <span class="counter">10</span></a></li>
    <li><a href="/iamnoah/writeCapture/downloads" class="" highlight="repo_downloads">Downloads <span class="counter">21</span></a></li>
  </ul>

</div>

  
  
  


        

      </div><!-- /.pagehead -->

      




  
  <p class="last-commit">Latest commit to the <strong>master</strong> branch</p>

<div class="commit commit-tease js-details-container">
  <p class="commit-title ">
      <a href="/iamnoah/writeCapture"><a href="/iamnoah/writeCapture/commit/6cbce2274c8d035a6bb6534b510299b2af32d1d7" class="message">Fix nolib insert.</a></a>
      
  </p>
  <div class="commit-meta">
    <a href="/iamnoah/writeCapture/commit/6cbce2274c8d035a6bb6534b510299b2af32d1d7" class="sha-block">commit <span class="sha">6cbce2274c</span></a>

    <div class="authorship">
      <img class="gravatar" height="20" src="https://secure.gravatar.com/avatar/755ad21d2059ac3970754edd621ba65b?s=140&amp;d=https://a248.e.akamai.net/assets.github.com%2Fimages%2Fgravatars%2Fgravatar-140.png" width="20" />
      <span class="author-name"><a href="/iamnoah">iamnoah</a></span>
      authored <time class="js-relative-date" datetime="2011-10-26T16:48:05-07:00" title="2011-10-26 16:48:05">October 26, 2011</time>

    </div>
  </div>
</div>


  <div id="slider">

    <div class="breadcrumb" data-path="plugin/jquery.writeCapture.js/">
      <b><a href="/iamnoah/writeCapture/tree/6cbce2274c8d035a6bb6534b510299b2af32d1d7" class="js-rewrite-sha">writeCapture</a></b> / <a href="/iamnoah/writeCapture/tree/6cbce2274c8d035a6bb6534b510299b2af32d1d7/plugin" class="js-rewrite-sha">plugin</a> / jquery.writeCapture.js       <span style="display:none" id="clippy_313" class="clippy-text">plugin/jquery.writeCapture.js</span>
      
      <object classid="clsid:d27cdb6e-ae6d-11cf-96b8-444553540000"
              width="110"
              height="14"
              class="clippy"
              id="clippy" >
      <param name="movie" value="https://a248.e.akamai.net/assets.github.com/flash/clippy.swf?v5"/>
      <param name="allowScriptAccess" value="always" />
      <param name="quality" value="high" />
      <param name="scale" value="noscale" />
      <param NAME="FlashVars" value="id=clippy_313&amp;copied=copied!&amp;copyto=copy to clipboard">
      <param name="bgcolor" value="#FFFFFF">
      <param name="wmode" value="opaque">
      <embed src="https://a248.e.akamai.net/assets.github.com/flash/clippy.swf?v5"
             width="110"
             height="14"
             name="clippy"
             quality="high"
             allowScriptAccess="always"
             type="application/x-shockwave-flash"
             pluginspage="http://www.macromedia.com/go/getflashplayer"
             FlashVars="id=clippy_313&amp;copied=copied!&amp;copyto=copy to clipboard"
             bgcolor="#FFFFFF"
             wmode="opaque"
      />
      </object>
      

    </div>

    <div class="frames">
      <div class="frame frame-center" data-path="plugin/jquery.writeCapture.js/" data-permalink-url="/iamnoah/writeCapture/blob/6cbce2274c8d035a6bb6534b510299b2af32d1d7/plugin/jquery.writeCapture.js" data-title="plugin/jquery.writeCapture.js at master from iamnoah/writeCapture - GitHub" data-type="blob">
          <ul class="big-actions">
            <li><a class="file-edit-link minibutton js-rewrite-sha" href="/iamnoah/writeCapture/edit/6cbce2274c8d035a6bb6534b510299b2af32d1d7/plugin/jquery.writeCapture.js" data-method="post"><span>Edit this file</span></a></li>
          </ul>

        <div id="files">
          <div class="file">
            <div class="meta">
              <div class="info">
                <span class="icon"><img alt="Txt" height="16" src="https://a248.e.akamai.net/assets.github.com/images/icons/txt.png" width="16" /></span>
                <span class="mode" title="File Mode">100644</span>
                  <span>155 lines (139 sloc)</span>
                <span>4.134 kb</span>
              </div>
              <ul class="actions">
                <li><a href="/iamnoah/writeCapture/raw/master/plugin/jquery.writeCapture.js" id="raw-url">raw</a></li>
                  <li><a href="/iamnoah/writeCapture/blame/master/plugin/jquery.writeCapture.js">blame</a></li>
                <li><a href="/iamnoah/writeCapture/commits/master/plugin/jquery.writeCapture.js">history</a></li>
              </ul>
            </div>
              <div class="data type-javascript">
      <table cellpadding="0" cellspacing="0" class="lines">
        <tr>
          <td>
            <pre class="line_numbers"><span id="L1" rel="#L1">1</span>
<span id="L2" rel="#L2">2</span>
<span id="L3" rel="#L3">3</span>
<span id="L4" rel="#L4">4</span>
<span id="L5" rel="#L5">5</span>
<span id="L6" rel="#L6">6</span>
<span id="L7" rel="#L7">7</span>
<span id="L8" rel="#L8">8</span>
<span id="L9" rel="#L9">9</span>
<span id="L10" rel="#L10">10</span>
<span id="L11" rel="#L11">11</span>
<span id="L12" rel="#L12">12</span>
<span id="L13" rel="#L13">13</span>
<span id="L14" rel="#L14">14</span>
<span id="L15" rel="#L15">15</span>
<span id="L16" rel="#L16">16</span>
<span id="L17" rel="#L17">17</span>
<span id="L18" rel="#L18">18</span>
<span id="L19" rel="#L19">19</span>
<span id="L20" rel="#L20">20</span>
<span id="L21" rel="#L21">21</span>
<span id="L22" rel="#L22">22</span>
<span id="L23" rel="#L23">23</span>
<span id="L24" rel="#L24">24</span>
<span id="L25" rel="#L25">25</span>
<span id="L26" rel="#L26">26</span>
<span id="L27" rel="#L27">27</span>
<span id="L28" rel="#L28">28</span>
<span id="L29" rel="#L29">29</span>
<span id="L30" rel="#L30">30</span>
<span id="L31" rel="#L31">31</span>
<span id="L32" rel="#L32">32</span>
<span id="L33" rel="#L33">33</span>
<span id="L34" rel="#L34">34</span>
<span id="L35" rel="#L35">35</span>
<span id="L36" rel="#L36">36</span>
<span id="L37" rel="#L37">37</span>
<span id="L38" rel="#L38">38</span>
<span id="L39" rel="#L39">39</span>
<span id="L40" rel="#L40">40</span>
<span id="L41" rel="#L41">41</span>
<span id="L42" rel="#L42">42</span>
<span id="L43" rel="#L43">43</span>
<span id="L44" rel="#L44">44</span>
<span id="L45" rel="#L45">45</span>
<span id="L46" rel="#L46">46</span>
<span id="L47" rel="#L47">47</span>
<span id="L48" rel="#L48">48</span>
<span id="L49" rel="#L49">49</span>
<span id="L50" rel="#L50">50</span>
<span id="L51" rel="#L51">51</span>
<span id="L52" rel="#L52">52</span>
<span id="L53" rel="#L53">53</span>
<span id="L54" rel="#L54">54</span>
<span id="L55" rel="#L55">55</span>
<span id="L56" rel="#L56">56</span>
<span id="L57" rel="#L57">57</span>
<span id="L58" rel="#L58">58</span>
<span id="L59" rel="#L59">59</span>
<span id="L60" rel="#L60">60</span>
<span id="L61" rel="#L61">61</span>
<span id="L62" rel="#L62">62</span>
<span id="L63" rel="#L63">63</span>
<span id="L64" rel="#L64">64</span>
<span id="L65" rel="#L65">65</span>
<span id="L66" rel="#L66">66</span>
<span id="L67" rel="#L67">67</span>
<span id="L68" rel="#L68">68</span>
<span id="L69" rel="#L69">69</span>
<span id="L70" rel="#L70">70</span>
<span id="L71" rel="#L71">71</span>
<span id="L72" rel="#L72">72</span>
<span id="L73" rel="#L73">73</span>
<span id="L74" rel="#L74">74</span>
<span id="L75" rel="#L75">75</span>
<span id="L76" rel="#L76">76</span>
<span id="L77" rel="#L77">77</span>
<span id="L78" rel="#L78">78</span>
<span id="L79" rel="#L79">79</span>
<span id="L80" rel="#L80">80</span>
<span id="L81" rel="#L81">81</span>
<span id="L82" rel="#L82">82</span>
<span id="L83" rel="#L83">83</span>
<span id="L84" rel="#L84">84</span>
<span id="L85" rel="#L85">85</span>
<span id="L86" rel="#L86">86</span>
<span id="L87" rel="#L87">87</span>
<span id="L88" rel="#L88">88</span>
<span id="L89" rel="#L89">89</span>
<span id="L90" rel="#L90">90</span>
<span id="L91" rel="#L91">91</span>
<span id="L92" rel="#L92">92</span>
<span id="L93" rel="#L93">93</span>
<span id="L94" rel="#L94">94</span>
<span id="L95" rel="#L95">95</span>
<span id="L96" rel="#L96">96</span>
<span id="L97" rel="#L97">97</span>
<span id="L98" rel="#L98">98</span>
<span id="L99" rel="#L99">99</span>
<span id="L100" rel="#L100">100</span>
<span id="L101" rel="#L101">101</span>
<span id="L102" rel="#L102">102</span>
<span id="L103" rel="#L103">103</span>
<span id="L104" rel="#L104">104</span>
<span id="L105" rel="#L105">105</span>
<span id="L106" rel="#L106">106</span>
<span id="L107" rel="#L107">107</span>
<span id="L108" rel="#L108">108</span>
<span id="L109" rel="#L109">109</span>
<span id="L110" rel="#L110">110</span>
<span id="L111" rel="#L111">111</span>
<span id="L112" rel="#L112">112</span>
<span id="L113" rel="#L113">113</span>
<span id="L114" rel="#L114">114</span>
<span id="L115" rel="#L115">115</span>
<span id="L116" rel="#L116">116</span>
<span id="L117" rel="#L117">117</span>
<span id="L118" rel="#L118">118</span>
<span id="L119" rel="#L119">119</span>
<span id="L120" rel="#L120">120</span>
<span id="L121" rel="#L121">121</span>
<span id="L122" rel="#L122">122</span>
<span id="L123" rel="#L123">123</span>
<span id="L124" rel="#L124">124</span>
<span id="L125" rel="#L125">125</span>
<span id="L126" rel="#L126">126</span>
<span id="L127" rel="#L127">127</span>
<span id="L128" rel="#L128">128</span>
<span id="L129" rel="#L129">129</span>
<span id="L130" rel="#L130">130</span>
<span id="L131" rel="#L131">131</span>
<span id="L132" rel="#L132">132</span>
<span id="L133" rel="#L133">133</span>
<span id="L134" rel="#L134">134</span>
<span id="L135" rel="#L135">135</span>
<span id="L136" rel="#L136">136</span>
<span id="L137" rel="#L137">137</span>
<span id="L138" rel="#L138">138</span>
<span id="L139" rel="#L139">139</span>
<span id="L140" rel="#L140">140</span>
<span id="L141" rel="#L141">141</span>
<span id="L142" rel="#L142">142</span>
<span id="L143" rel="#L143">143</span>
<span id="L144" rel="#L144">144</span>
<span id="L145" rel="#L145">145</span>
<span id="L146" rel="#L146">146</span>
<span id="L147" rel="#L147">147</span>
<span id="L148" rel="#L148">148</span>
<span id="L149" rel="#L149">149</span>
<span id="L150" rel="#L150">150</span>
<span id="L151" rel="#L151">151</span>
<span id="L152" rel="#L152">152</span>
<span id="L153" rel="#L153">153</span>
<span id="L154" rel="#L154">154</span>
<span id="L155" rel="#L155">155</span>
</pre>
          </td>
          <td width="100%">
                <div class="highlight"><pre><div class='line' id='LC1'><span class="cm">/**</span></div><div class='line' id='LC2'><span class="cm"> * jquery.writeCapture.js </span></div><div class='line' id='LC3'><span class="cm"> * </span></div><div class='line' id='LC4'><span class="cm"> * Note that this file only provides the jQuery plugin functionality, you still</span></div><div class='line' id='LC5'><span class="cm"> * need writeCapture.js. The compressed version will contain both as as single</span></div><div class='line' id='LC6'><span class="cm"> * file.</span></div><div class='line' id='LC7'><span class="cm"> *</span></div><div class='line' id='LC8'><span class="cm"> * @author noah &lt;noah.sloan@gmail.com&gt;</span></div><div class='line' id='LC9'><span class="cm"> * </span></div><div class='line' id='LC10'><span class="cm"> */</span></div><div class='line' id='LC11'><span class="p">(</span><span class="kd">function</span><span class="p">(</span><span class="nx">$</span><span class="p">,</span><span class="nx">wc</span><span class="p">,</span><span class="nx">noop</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC12'>	<span class="c1">// methods that take HTML content (according to API)</span></div><div class='line' id='LC13'>	<span class="kd">var</span> <span class="nx">methods</span> <span class="o">=</span> <span class="p">{</span></div><div class='line' id='LC14'>		<span class="nx">html</span><span class="o">:</span> <span class="nx">html</span></div><div class='line' id='LC15'>	<span class="p">};</span></div><div class='line' id='LC16'>	<span class="c1">// TODO wrap domManip instead?</span></div><div class='line' id='LC17'>	<span class="nx">$</span><span class="p">.</span><span class="nx">each</span><span class="p">([</span><span class="s1">&#39;append&#39;</span><span class="p">,</span> <span class="s1">&#39;prepend&#39;</span><span class="p">,</span> <span class="s1">&#39;after&#39;</span><span class="p">,</span> <span class="s1">&#39;before&#39;</span><span class="p">,</span> <span class="s1">&#39;wrap&#39;</span><span class="p">,</span> <span class="s1">&#39;wrapAll&#39;</span><span class="p">,</span> <span class="s1">&#39;replaceWith&#39;</span><span class="p">,</span></div><div class='line' id='LC18'>		<span class="s1">&#39;wrapInner&#39;</span><span class="p">],</span><span class="kd">function</span><span class="p">()</span> <span class="p">{</span> <span class="nx">methods</span><span class="p">[</span><span class="k">this</span><span class="p">]</span> <span class="o">=</span> <span class="nx">makeMethod</span><span class="p">(</span><span class="k">this</span><span class="p">);</span> <span class="p">});</span></div><div class='line' id='LC19'><br/></div><div class='line' id='LC20'>	<span class="kd">function</span> <span class="nx">isString</span><span class="p">(</span><span class="nx">s</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC21'>		<span class="k">return</span> <span class="nb">Object</span><span class="p">.</span><span class="nx">prototype</span><span class="p">.</span><span class="nx">toString</span><span class="p">.</span><span class="nx">call</span><span class="p">(</span><span class="nx">s</span><span class="p">)</span> <span class="o">==</span> <span class="s2">&quot;[object String]&quot;</span><span class="p">;</span></div><div class='line' id='LC22'>	<span class="p">}</span></div><div class='line' id='LC23'><br/></div><div class='line' id='LC24'>	<span class="kd">function</span> <span class="nx">executeMethod</span><span class="p">(</span><span class="nx">method</span><span class="p">,</span><span class="nx">content</span><span class="p">,</span><span class="nx">options</span><span class="p">,</span><span class="nx">cb</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC25'>		<span class="k">if</span><span class="p">(</span><span class="nx">arguments</span><span class="p">.</span><span class="nx">length</span> <span class="o">==</span> <span class="mi">0</span><span class="p">)</span> <span class="k">return</span> <span class="nx">proxyMethods</span><span class="p">.</span><span class="nx">call</span><span class="p">(</span><span class="k">this</span><span class="p">);</span></div><div class='line' id='LC26'><br/></div><div class='line' id='LC27'>		<span class="kd">var</span> <span class="nx">m</span> <span class="o">=</span> <span class="nx">methods</span><span class="p">[</span><span class="nx">method</span><span class="p">];</span></div><div class='line' id='LC28'>		<span class="k">if</span><span class="p">(</span><span class="nx">method</span> <span class="o">==</span> <span class="s1">&#39;load&#39;</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC29'>			<span class="k">return</span> <span class="nx">load</span><span class="p">.</span><span class="nx">call</span><span class="p">(</span><span class="k">this</span><span class="p">,</span><span class="nx">content</span><span class="p">,</span><span class="nx">options</span><span class="p">,</span><span class="nx">cb</span><span class="p">);</span></div><div class='line' id='LC30'>		<span class="p">}</span></div><div class='line' id='LC31'>		<span class="k">if</span><span class="p">(</span><span class="o">!</span><span class="nx">m</span><span class="p">)</span> <span class="nx">error</span><span class="p">(</span><span class="nx">method</span><span class="p">);</span></div><div class='line' id='LC32'>		<span class="k">return</span> <span class="nx">doEach</span><span class="p">.</span><span class="nx">call</span><span class="p">(</span><span class="k">this</span><span class="p">,</span><span class="nx">content</span><span class="p">,</span><span class="nx">options</span><span class="p">,</span><span class="nx">m</span><span class="p">);</span></div><div class='line' id='LC33'>	<span class="p">}</span></div><div class='line' id='LC34'><br/></div><div class='line' id='LC35'>	<span class="nx">$</span><span class="p">.</span><span class="nx">fn</span><span class="p">.</span><span class="nx">writeCapture</span> <span class="o">=</span> <span class="nx">executeMethod</span><span class="p">;</span></div><div class='line' id='LC36'><br/></div><div class='line' id='LC37'>	<span class="kd">var</span> <span class="nx">PROXIED</span> <span class="o">=</span> <span class="s1">&#39;__writeCaptureJsProxied-fghebd__&#39;</span><span class="p">;</span></div><div class='line' id='LC38'>	<span class="c1">// inherit from the jQuery instance, proxying the HTML injection methods</span></div><div class='line' id='LC39'>	<span class="c1">// so that the HTML is sanitized</span></div><div class='line' id='LC40'>	<span class="kd">function</span> <span class="nx">proxyMethods</span><span class="p">()</span> <span class="p">{</span></div><div class='line' id='LC41'>		<span class="k">if</span><span class="p">(</span><span class="k">this</span><span class="p">[</span><span class="nx">PROXIED</span><span class="p">])</span> <span class="k">return</span> <span class="k">this</span><span class="p">;</span></div><div class='line' id='LC42'><br/></div><div class='line' id='LC43'>		<span class="kd">var</span> <span class="nx">jq</span> <span class="o">=</span> <span class="k">this</span><span class="p">;</span></div><div class='line' id='LC44'>		<span class="kd">function</span> <span class="nx">F</span><span class="p">()</span> <span class="p">{</span></div><div class='line' id='LC45'>			<span class="kd">var</span> <span class="nx">_this</span> <span class="o">=</span> <span class="k">this</span><span class="p">,</span> <span class="nx">sanitizing</span> <span class="o">=</span> <span class="kc">false</span><span class="p">;</span></div><div class='line' id='LC46'>			<span class="k">this</span><span class="p">[</span><span class="nx">PROXIED</span><span class="p">]</span> <span class="o">=</span> <span class="kc">true</span><span class="p">;</span></div><div class='line' id='LC47'>			<span class="nx">$</span><span class="p">.</span><span class="nx">each</span><span class="p">(</span><span class="nx">methods</span><span class="p">,</span><span class="kd">function</span><span class="p">(</span><span class="nx">method</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC48'>				<span class="kd">var</span> <span class="nx">_super</span> <span class="o">=</span> <span class="nx">jq</span><span class="p">[</span><span class="nx">method</span><span class="p">];</span></div><div class='line' id='LC49'>				<span class="k">if</span><span class="p">(</span><span class="o">!</span><span class="nx">_super</span><span class="p">)</span> <span class="k">return</span><span class="p">;</span></div><div class='line' id='LC50'>				<span class="nx">_this</span><span class="p">[</span><span class="nx">method</span><span class="p">]</span> <span class="o">=</span> <span class="kd">function</span><span class="p">(</span><span class="nx">content</span><span class="p">,</span><span class="nx">options</span><span class="p">,</span><span class="nx">cb</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC51'>					<span class="c1">// if it&#39;s unsanitized HTML, proxy it</span></div><div class='line' id='LC52'>					<span class="k">if</span><span class="p">(</span><span class="o">!</span><span class="nx">sanitizing</span> <span class="o">&amp;&amp;</span> <span class="nx">isString</span><span class="p">(</span><span class="nx">content</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC53'>						<span class="k">try</span> <span class="p">{</span></div><div class='line' id='LC54'>							<span class="nx">sanitizing</span> <span class="o">=</span> <span class="kc">true</span><span class="p">;</span></div><div class='line' id='LC55'>							<span class="k">return</span> <span class="nx">executeMethod</span><span class="p">.</span><span class="nx">call</span><span class="p">(</span><span class="nx">_this</span><span class="p">,</span><span class="nx">method</span><span class="p">,</span><span class="nx">content</span><span class="p">,</span></div><div class='line' id='LC56'>								<span class="nx">options</span><span class="p">,</span><span class="nx">cb</span><span class="p">);</span></div><div class='line' id='LC57'>						<span class="p">}</span> <span class="k">finally</span> <span class="p">{</span></div><div class='line' id='LC58'>							<span class="nx">sanitizing</span> <span class="o">=</span> <span class="kc">false</span><span class="p">;</span></div><div class='line' id='LC59'>						<span class="p">}</span></div><div class='line' id='LC60'>					<span class="p">}</span> </div><div class='line' id='LC61'>					<span class="k">return</span> <span class="nx">_super</span><span class="p">.</span><span class="nx">apply</span><span class="p">(</span><span class="nx">_this</span><span class="p">,</span><span class="nx">arguments</span><span class="p">);</span> <span class="c1">// else delegate</span></div><div class='line' id='LC62'>				<span class="p">};</span></div><div class='line' id='LC63'>			<span class="p">});</span></div><div class='line' id='LC64'>			<span class="c1">// wrap pushStack so that the new jQuery instance is also wrapped</span></div><div class='line' id='LC65'>			<span class="k">this</span><span class="p">.</span><span class="nx">pushStack</span> <span class="o">=</span> <span class="kd">function</span><span class="p">()</span> <span class="p">{</span></div><div class='line' id='LC66'>				<span class="k">return</span> <span class="nx">proxyMethods</span><span class="p">.</span><span class="nx">call</span><span class="p">(</span><span class="nx">jq</span><span class="p">.</span><span class="nx">pushStack</span><span class="p">.</span><span class="nx">apply</span><span class="p">(</span><span class="nx">_this</span><span class="p">,</span><span class="nx">arguments</span><span class="p">));</span></div><div class='line' id='LC67'>			<span class="p">};</span></div><div class='line' id='LC68'>			<span class="k">this</span><span class="p">.</span><span class="nx">endCapture</span> <span class="o">=</span> <span class="kd">function</span><span class="p">()</span> <span class="p">{</span> <span class="k">return</span> <span class="nx">jq</span><span class="p">;</span> <span class="p">};</span></div><div class='line' id='LC69'>		<span class="p">}</span></div><div class='line' id='LC70'>		<span class="nx">F</span><span class="p">.</span><span class="nx">prototype</span> <span class="o">=</span> <span class="nx">jq</span><span class="p">;</span></div><div class='line' id='LC71'>		<span class="k">return</span> <span class="k">new</span> <span class="nx">F</span><span class="p">();</span></div><div class='line' id='LC72'>	<span class="p">}</span></div><div class='line' id='LC73'><br/></div><div class='line' id='LC74'>	<span class="kd">function</span> <span class="nx">doEach</span><span class="p">(</span><span class="nx">content</span><span class="p">,</span><span class="nx">options</span><span class="p">,</span><span class="nx">action</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC75'>		<span class="kd">var</span> <span class="nx">done</span><span class="p">,</span> <span class="nx">self</span> <span class="o">=</span> <span class="k">this</span><span class="p">;</span></div><div class='line' id='LC76'>		<span class="k">if</span><span class="p">(</span><span class="nx">options</span> <span class="o">&amp;&amp;</span> <span class="nx">options</span><span class="p">.</span><span class="nx">done</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC77'>			<span class="nx">done</span> <span class="o">=</span> <span class="nx">options</span><span class="p">.</span><span class="nx">done</span><span class="p">;</span></div><div class='line' id='LC78'>			<span class="k">delete</span> <span class="nx">options</span><span class="p">.</span><span class="nx">done</span><span class="p">;</span></div><div class='line' id='LC79'>		<span class="p">}</span> <span class="k">else</span> <span class="k">if</span><span class="p">(</span><span class="nx">$</span><span class="p">.</span><span class="nx">isFunction</span><span class="p">(</span><span class="nx">options</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC80'>			<span class="nx">done</span> <span class="o">=</span> <span class="nx">options</span><span class="p">;</span></div><div class='line' id='LC81'>			<span class="nx">options</span> <span class="o">=</span> <span class="kc">null</span><span class="p">;</span></div><div class='line' id='LC82'>		<span class="p">}</span></div><div class='line' id='LC83'>		<span class="nx">wc</span><span class="p">.</span><span class="nx">sanitizeSerial</span><span class="p">(</span><span class="nx">$</span><span class="p">.</span><span class="nx">map</span><span class="p">(</span><span class="k">this</span><span class="p">,</span><span class="kd">function</span><span class="p">(</span><span class="nx">el</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC84'>			<span class="k">return</span> <span class="p">{</span></div><div class='line' id='LC85'>				<span class="nx">html</span><span class="o">:</span> <span class="nx">content</span><span class="p">,</span></div><div class='line' id='LC86'>				<span class="nx">options</span><span class="o">:</span> <span class="nx">options</span><span class="p">,</span></div><div class='line' id='LC87'>				<span class="nx">action</span><span class="o">:</span> <span class="kd">function</span><span class="p">(</span><span class="nx">text</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC88'>					<span class="nx">action</span><span class="p">.</span><span class="nx">call</span><span class="p">(</span><span class="nx">el</span><span class="p">,</span><span class="nx">text</span><span class="p">);</span></div><div class='line' id='LC89'>				<span class="p">}</span></div><div class='line' id='LC90'>			<span class="p">};</span></div><div class='line' id='LC91'>		<span class="p">}),</span><span class="nx">done</span> <span class="o">&amp;&amp;</span> <span class="kd">function</span><span class="p">()</span> <span class="p">{</span> <span class="nx">done</span><span class="p">.</span><span class="nx">call</span><span class="p">(</span><span class="nx">self</span><span class="p">);</span> <span class="p">}</span> <span class="o">||</span> <span class="nx">done</span><span class="p">);</span></div><div class='line' id='LC92'>		<span class="k">return</span> <span class="k">this</span><span class="p">;</span></div><div class='line' id='LC93'>	<span class="p">}</span></div><div class='line' id='LC94'><br/></div><div class='line' id='LC95'><br/></div><div class='line' id='LC96'>	<span class="kd">function</span> <span class="nx">html</span><span class="p">(</span><span class="nx">safe</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC97'>		<span class="nx">$</span><span class="p">(</span><span class="k">this</span><span class="p">).</span><span class="nx">html</span><span class="p">(</span><span class="nx">safe</span><span class="p">);</span></div><div class='line' id='LC98'>	<span class="p">}</span></div><div class='line' id='LC99'><br/></div><div class='line' id='LC100'>	<span class="kd">function</span> <span class="nx">makeMethod</span><span class="p">(</span><span class="nx">method</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC101'>		<span class="k">return</span> <span class="kd">function</span><span class="p">(</span><span class="nx">safe</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC102'>			<span class="nx">$</span><span class="p">(</span><span class="k">this</span><span class="p">)[</span><span class="nx">method</span><span class="p">](</span><span class="nx">safe</span><span class="p">);</span></div><div class='line' id='LC103'>		<span class="p">};</span></div><div class='line' id='LC104'>	<span class="p">}</span></div><div class='line' id='LC105'><br/></div><div class='line' id='LC106'>	<span class="kd">function</span> <span class="nx">load</span><span class="p">(</span><span class="nx">url</span><span class="p">,</span><span class="nx">options</span><span class="p">,</span><span class="nx">callback</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC107'>		<span class="kd">var</span> <span class="nx">self</span> <span class="o">=</span> <span class="k">this</span><span class="p">,</span>  <span class="nx">selector</span><span class="p">,</span> <span class="nx">off</span> <span class="o">=</span> <span class="nx">url</span><span class="p">.</span><span class="nx">indexOf</span><span class="p">(</span><span class="s1">&#39; &#39;</span><span class="p">);</span></div><div class='line' id='LC108'>		<span class="k">if</span> <span class="p">(</span> <span class="nx">off</span> <span class="o">&gt;=</span> <span class="mi">0</span> <span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC109'>			<span class="nx">selector</span> <span class="o">=</span> <span class="nx">url</span><span class="p">.</span><span class="nx">slice</span><span class="p">(</span><span class="nx">off</span><span class="p">,</span> <span class="nx">url</span><span class="p">.</span><span class="nx">length</span><span class="p">);</span></div><div class='line' id='LC110'>			<span class="nx">url</span> <span class="o">=</span> <span class="nx">url</span><span class="p">.</span><span class="nx">slice</span><span class="p">(</span><span class="mi">0</span><span class="p">,</span> <span class="nx">off</span><span class="p">);</span></div><div class='line' id='LC111'>		<span class="p">}</span></div><div class='line' id='LC112'>		<span class="k">if</span><span class="p">(</span><span class="nx">$</span><span class="p">.</span><span class="nx">isFunction</span><span class="p">(</span><span class="nx">callback</span><span class="p">))</span> <span class="p">{</span></div><div class='line' id='LC113'>			<span class="nx">options</span> <span class="o">=</span> <span class="nx">options</span> <span class="o">||</span> <span class="p">{};</span></div><div class='line' id='LC114'>			<span class="nx">options</span><span class="p">.</span><span class="nx">done</span> <span class="o">=</span> <span class="nx">callback</span><span class="p">;</span></div><div class='line' id='LC115'>		<span class="p">}</span></div><div class='line' id='LC116'>		<span class="k">return</span> <span class="nx">$</span><span class="p">.</span><span class="nx">ajax</span><span class="p">({</span></div><div class='line' id='LC117'>			<span class="nx">url</span><span class="o">:</span> <span class="nx">url</span><span class="p">,</span></div><div class='line' id='LC118'>			<span class="nx">type</span><span class="o">:</span>  <span class="nx">options</span> <span class="o">&amp;&amp;</span> <span class="nx">options</span><span class="p">.</span><span class="nx">type</span> <span class="o">||</span> <span class="s2">&quot;GET&quot;</span><span class="p">,</span></div><div class='line' id='LC119'>			<span class="nx">dataType</span><span class="o">:</span> <span class="s2">&quot;html&quot;</span><span class="p">,</span></div><div class='line' id='LC120'>			<span class="nx">data</span><span class="o">:</span> <span class="nx">options</span> <span class="o">&amp;&amp;</span> <span class="nx">options</span><span class="p">.</span><span class="nx">params</span><span class="p">,</span></div><div class='line' id='LC121'>			<span class="nx">complete</span><span class="o">:</span> <span class="nx">loadCallback</span><span class="p">(</span><span class="nx">self</span><span class="p">,</span><span class="nx">options</span><span class="p">,</span><span class="nx">selector</span><span class="p">)</span></div><div class='line' id='LC122'>		<span class="p">});</span></div><div class='line' id='LC123'>	<span class="p">}</span></div><div class='line' id='LC124'><br/></div><div class='line' id='LC125'>	<span class="kd">function</span> <span class="nx">loadCallback</span><span class="p">(</span><span class="nx">self</span><span class="p">,</span><span class="nx">options</span><span class="p">,</span><span class="nx">selector</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC126'>		<span class="k">return</span> <span class="kd">function</span><span class="p">(</span><span class="nx">res</span><span class="p">,</span><span class="nx">status</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC127'>			<span class="k">if</span> <span class="p">(</span> <span class="nx">status</span> <span class="o">==</span> <span class="s2">&quot;success&quot;</span> <span class="o">||</span> <span class="nx">status</span> <span class="o">==</span> <span class="s2">&quot;notmodified&quot;</span> <span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC128'>				<span class="kd">var</span> <span class="nx">text</span> <span class="o">=</span> <span class="nx">getText</span><span class="p">(</span><span class="nx">res</span><span class="p">.</span><span class="nx">responseText</span><span class="p">,</span><span class="nx">selector</span><span class="p">);</span></div><div class='line' id='LC129'>				<span class="nx">doEach</span><span class="p">.</span><span class="nx">call</span><span class="p">(</span><span class="nx">self</span><span class="p">,</span><span class="nx">text</span><span class="p">,</span><span class="nx">options</span><span class="p">,</span><span class="nx">html</span><span class="p">);</span></div><div class='line' id='LC130'>			<span class="p">}</span></div><div class='line' id='LC131'>		<span class="p">};</span></div><div class='line' id='LC132'>	<span class="p">}</span></div><div class='line' id='LC133'><br/></div><div class='line' id='LC134'>	<span class="kd">var</span> <span class="nx">PLACEHOLDER</span> <span class="o">=</span> <span class="sr">/jquery-writeCapture-script-placeholder-(\d+)-wc/g</span><span class="p">;</span></div><div class='line' id='LC135'>	<span class="kd">function</span> <span class="nx">getText</span><span class="p">(</span><span class="nx">text</span><span class="p">,</span><span class="nx">selector</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC136'>		<span class="k">if</span><span class="p">(</span><span class="o">!</span><span class="nx">selector</span> <span class="o">||</span> <span class="o">!</span><span class="nx">text</span><span class="p">)</span> <span class="k">return</span> <span class="nx">text</span><span class="p">;</span></div><div class='line' id='LC137'><br/></div><div class='line' id='LC138'>		<span class="kd">var</span> <span class="nx">id</span> <span class="o">=</span> <span class="mi">0</span><span class="p">,</span> <span class="nx">scripts</span> <span class="o">=</span> <span class="p">{};</span>			</div><div class='line' id='LC139'>		<span class="k">return</span> <span class="nx">$</span><span class="p">(</span><span class="s1">&#39;&lt;div/&gt;&#39;</span><span class="p">).</span><span class="nx">append</span><span class="p">(</span></div><div class='line' id='LC140'>			<span class="nx">text</span><span class="p">.</span><span class="nx">replace</span><span class="p">(</span><span class="sr">/&lt;script(.|\s)*?\/script&gt;/g</span><span class="p">,</span> <span class="kd">function</span><span class="p">(</span><span class="nx">s</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC141'>				<span class="nx">scripts</span><span class="p">[</span><span class="nx">id</span><span class="p">]</span> <span class="o">=</span> <span class="nx">s</span><span class="p">;</span></div><div class='line' id='LC142'>				<span class="k">return</span> <span class="s2">&quot;jquery-writeCapture-script-placeholder-&quot;</span><span class="o">+</span><span class="p">(</span><span class="nx">id</span><span class="o">++</span><span class="p">)</span><span class="o">+</span><span class="s1">&#39;-wc&#39;</span><span class="p">;</span></div><div class='line' id='LC143'>			<span class="p">})</span></div><div class='line' id='LC144'>		<span class="p">).</span><span class="nx">find</span><span class="p">(</span><span class="nx">selector</span><span class="p">).</span><span class="nx">html</span><span class="p">().</span><span class="nx">replace</span><span class="p">(</span><span class="nx">PLACEHOLDER</span><span class="p">,</span><span class="kd">function</span><span class="p">(</span><span class="nx">all</span><span class="p">,</span><span class="nx">id</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC145'>			<span class="k">return</span> <span class="nx">scripts</span><span class="p">[</span><span class="nx">id</span><span class="p">];</span></div><div class='line' id='LC146'>		<span class="p">});</span></div><div class='line' id='LC147'>	<span class="p">}</span></div><div class='line' id='LC148'><br/></div><div class='line' id='LC149'>	<span class="kd">function</span> <span class="nx">error</span><span class="p">(</span><span class="nx">method</span><span class="p">)</span> <span class="p">{</span></div><div class='line' id='LC150'>		<span class="k">throw</span> <span class="s2">&quot;invalid method parameter &quot;</span><span class="o">+</span><span class="nx">method</span><span class="p">;</span></div><div class='line' id='LC151'>	<span class="p">}</span></div><div class='line' id='LC152'><br/></div><div class='line' id='LC153'>	<span class="c1">// expose core</span></div><div class='line' id='LC154'>	<span class="nx">$</span><span class="p">.</span><span class="nx">writeCapture</span> <span class="o">=</span> <span class="nx">wc</span><span class="p">;</span></div><div class='line' id='LC155'><span class="p">})(</span><span class="nx">jQuery</span><span class="p">,</span><span class="nx">writeCapture</span><span class="p">.</span><span class="nx">noConflict</span><span class="p">());</span></div></pre></div>
          </td>
        </tr>
      </table>
  </div>

          </div>
        </div>
      </div>
    </div>

  </div>

<div class="frame frame-loading" style="display:none;" data-tree-list-url="/iamnoah/writeCapture/tree-list/6cbce2274c8d035a6bb6534b510299b2af32d1d7" data-blob-url-prefix="/iamnoah/writeCapture/blob/6cbce2274c8d035a6bb6534b510299b2af32d1d7">
  <img src="https://a248.e.akamai.net/assets.github.com/images/modules/ajax/big_spinner_336699.gif" height="32" width="32">
</div>

    </div>

    </div>

    <!-- footer -->
    <div id="footer" >
      
  <div class="upper_footer">
     <div class="site" class="clearfix">

       <!--[if IE]><h4 id="blacktocat_ie">GitHub Links</h4><![endif]-->
       <![if !IE]><h4 id="blacktocat">GitHub Links</h4><![endif]>

       <ul class="footer_nav">
         <h4>GitHub</h4>
         <li><a href="https://github.com/about">About</a></li>
         <li><a href="https://github.com/blog">Blog</a></li>
         <li><a href="https://github.com/features">Features</a></li>
         <li><a href="https://github.com/contact">Contact &amp; Support</a></li>
         <li><a href="https://github.com/training">Training</a></li>
         <li><a href="http://status.github.com/">Site Status</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Tools</h4>
         <li><a href="http://mac.github.com/">GitHub for Mac</a></li>
         <li><a href="http://mobile.github.com/">Issues for iPhone</a></li>
         <li><a href="https://gist.github.com">Gist: Code Snippets</a></li>
         <li><a href="http://fi.github.com/">Enterprise Install</a></li>
         <li><a href="http://jobs.github.com/">Job Board</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Extras</h4>
         <li><a href="http://shop.github.com/">GitHub Shop</a></li>
         <li><a href="http://octodex.github.com/">The Octodex</a></li>
       </ul>

       <ul class="footer_nav">
         <h4>Documentation</h4>
         <li><a href="http://help.github.com/">GitHub Help</a></li>
         <li><a href="http://developer.github.com/">Developer API</a></li>
         <li><a href="http://github.github.com/github-flavored-markdown/">GitHub Flavored Markdown</a></li>
         <li><a href="http://pages.github.com/">GitHub Pages</a></li>
       </ul>

     </div><!-- /.site -->
  </div><!-- /.upper_footer -->

<div class="lower_footer">
  <div class="site" class="clearfix">
    <!--[if IE]><div id="legal_ie"><![endif]-->
    <![if !IE]><div id="legal"><![endif]>
      <ul>
          <li><a href="https://github.com/site/terms">Terms of Service</a></li>
          <li><a href="https://github.com/site/privacy">Privacy</a></li>
          <li><a href="https://github.com/security">Security</a></li>
      </ul>

      <p>&copy; 2011 <span id="_rrt" title="0.06839s from fe3.rs.github.com">GitHub</span> Inc. All rights reserved.</p>
    </div><!-- /#legal or /#legal_ie-->

      <div class="sponsor">
        <a href="http://www.rackspace.com" class="logo">
          <img alt="Dedicated Server" height="36" src="https://a248.e.akamai.net/assets.github.com/images/modules/footer/rackspace_logo.png?v2" width="38" />
        </a>
        Powered by the <a href="http://www.rackspace.com ">Dedicated
        Servers</a> and<br/> <a href="http://www.rackspacecloud.com">Cloud
        Computing</a> of Rackspace Hosting<span>&reg;</span>
      </div>
  </div><!-- /.site -->
</div><!-- /.lower_footer -->

    </div><!-- /#footer -->

    

<div id="keyboard_shortcuts_pane" class="instapaper_ignore readability-extra" style="display:none">
  <h2>Keyboard Shortcuts <small><a href="#" class="js-see-all-keyboard-shortcuts">(see all)</a></small></h2>

  <div class="columns threecols">
    <div class="column first">
      <h3>Site wide shortcuts</h3>
      <dl class="keyboard-mappings">
        <dt>s</dt>
        <dd>Focus site search</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>?</dt>
        <dd>Bring up this help dialog</dd>
      </dl>
    </div><!-- /.column.first -->

    <div class="column middle" style=&#39;display:none&#39;>
      <h3>Commit list</h3>
      <dl class="keyboard-mappings">
        <dt>j</dt>
        <dd>Move selection down</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>k</dt>
        <dd>Move selection up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>c <em>or</em> o <em>or</em> enter</dt>
        <dd>Open commit</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>y</dt>
        <dd>Expand URL to its canonical form</dd>
      </dl>
    </div><!-- /.column.first -->

    <div class="column last" style=&#39;display:none&#39;>
      <h3>Pull request list</h3>
      <dl class="keyboard-mappings">
        <dt>j</dt>
        <dd>Move selection down</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>k</dt>
        <dd>Move selection up</dd>
      </dl>
      <dl class="keyboard-mappings">
        <dt>o <em>or</em> enter</dt>
        <dd>Open issue</dd>
      </dl>
    </div><!-- /.columns.last -->

  </div><!-- /.columns.equacols -->

  <div style=&#39;display:none&#39;>
    <div class="rule"></div>

    <h3>Issues</h3>

    <div class="columns threecols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt>j</dt>
          <dd>Move selection down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>k</dt>
          <dd>Move selection up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>x</dt>
          <dd>Toggle selection</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>o <em>or</em> enter</dt>
          <dd>Open issue</dd>
        </dl>
      </div><!-- /.column.first -->
      <div class="column middle">
        <dl class="keyboard-mappings">
          <dt>I</dt>
          <dd>Mark selection as read</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>U</dt>
          <dd>Mark selection as unread</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>e</dt>
          <dd>Close selection</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>y</dt>
          <dd>Remove selection from view</dd>
        </dl>
      </div><!-- /.column.middle -->
      <div class="column last">
        <dl class="keyboard-mappings">
          <dt>c</dt>
          <dd>Create issue</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>l</dt>
          <dd>Create label</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>i</dt>
          <dd>Back to inbox</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>u</dt>
          <dd>Back to issues</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>/</dt>
          <dd>Focus issues search</dd>
        </dl>
      </div>
    </div>
  </div>

  <div style=&#39;display:none&#39;>
    <div class="rule"></div>

    <h3>Issues Dashboard</h3>

    <div class="columns threecols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt>j</dt>
          <dd>Move selection down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>k</dt>
          <dd>Move selection up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>o <em>or</em> enter</dt>
          <dd>Open issue</dd>
        </dl>
      </div><!-- /.column.first -->
    </div>
  </div>

  <div style=&#39;display:none&#39;>
    <div class="rule"></div>

    <h3>Network Graph</h3>
    <div class="columns equacols">
      <div class="column first">
        <dl class="keyboard-mappings">
          <dt><span class="badmono">←</span> <em>or</em> h</dt>
          <dd>Scroll left</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">→</span> <em>or</em> l</dt>
          <dd>Scroll right</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">↑</span> <em>or</em> k</dt>
          <dd>Scroll up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt><span class="badmono">↓</span> <em>or</em> j</dt>
          <dd>Scroll down</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>t</dt>
          <dd>Toggle visibility of head labels</dd>
        </dl>
      </div><!-- /.column.first -->
      <div class="column last">
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">←</span> <em>or</em> shift h</dt>
          <dd>Scroll all the way left</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">→</span> <em>or</em> shift l</dt>
          <dd>Scroll all the way right</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">↑</span> <em>or</em> shift k</dt>
          <dd>Scroll all the way up</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>shift <span class="badmono">↓</span> <em>or</em> shift j</dt>
          <dd>Scroll all the way down</dd>
        </dl>
      </div><!-- /.column.last -->
    </div>
  </div>

  <div >
    <div class="rule"></div>
    <div class="columns threecols">
      <div class="column first" >
        <h3>Source Code Browsing</h3>
        <dl class="keyboard-mappings">
          <dt>t</dt>
          <dd>Activates the file finder</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>l</dt>
          <dd>Jump to line</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>w</dt>
          <dd>Switch branch/tag</dd>
        </dl>
        <dl class="keyboard-mappings">
          <dt>y</dt>
          <dd>Expand URL to its canonical form</dd>
        </dl>
      </div>
    </div>
  </div>
</div>

    <div id="markdown-help" class="instapaper_ignore readability-extra">
  <h2>Markdown Cheat Sheet</h2>

  <div class="cheatsheet-content">

  <div class="mod">
    <div class="col">
      <h3>Format Text</h3>
      <p>Headers</p>
      <pre>
# This is an &lt;h1&gt; tag
## This is an &lt;h2&gt; tag
###### This is an &lt;h6&gt; tag</pre>
     <p>Text styles</p>
     <pre>
*This text will be italic*
_This will also be italic_
**This text will be bold**
__This will also be bold__

*You **can** combine them*
</pre>
    </div>
    <div class="col">
      <h3>Lists</h3>
      <p>Unordered</p>
      <pre>
* Item 1
* Item 2
  * Item 2a
  * Item 2b</pre>
     <p>Ordered</p>
     <pre>
1. Item 1
2. Item 2
3. Item 3
   * Item 3a
   * Item 3b</pre>
    </div>
    <div class="col">
      <h3>Miscellaneous</h3>
      <p>Images</p>
      <pre>
![GitHub Logo](/images/logo.png)
Format: ![Alt Text](url)
</pre>
     <p>Links</p>
     <pre>
http://github.com - automatic!
[GitHub](http://github.com)</pre>
<p>Blockquotes</p>
     <pre>
As Kanye West said:
> We're living the future so
> the present is our past.
</pre>
    </div>
  </div>
  <div class="rule"></div>

  <h3>Code Examples in Markdown</h3>
  <div class="col">
      <p>Syntax highlighting with <a href="http://github.github.com/github-flavored-markdown/" title="GitHub Flavored Markdown" target="_blank">GFM</a></p>
      <pre>
```javascript
function fancyAlert(arg) {
  if(arg) {
    $.facebox({div:'#foo'})
  }
}
```</pre>
    </div>
    <div class="col">
      <p>Or, indent your code 4 spaces</p>
      <pre>
Here is a Python code example
without syntax highlighting:

    def foo:
      if not bar:
        return true</pre>
    </div>
    <div class="col">
      <p>Inline code for comments</p>
      <pre>
I think you should use an
`&lt;addr&gt;` element here instead.</pre>
    </div>
  </div>

  </div>
</div>

    <div class="context-overlay"></div>

    
    
    
  </body>
</html>

