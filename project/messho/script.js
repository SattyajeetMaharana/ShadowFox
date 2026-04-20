/* ========================================
   MEESHO REDESIGN - script.js
   ======================================== */

// ========== PRODUCT DATA ==========
const products = [
  { id:1, brand:"Libas", name:"Floral Printed Anarkali Kurti", price:349, mrp:899, off:61, rating:4.3, reviews:"12.4k", img:"https://images.unsplash.com/photo-1583391733981-8498408ee4b2?w=300&h=380&fit=crop", sizes:["XS","S","M","L","XL"], badge:"trending", seller:"TopFashion", category:"kurti" },
  { id:2, brand:"BIBA", name:"Ethnic Wear Straight Kurta", price:499, mrp:1199, off:58, rating:4.5, reviews:"8.2k", img:"https://images.unsplash.com/photo-1610030469983-98e550d6193c?w=300&h=380&fit=crop", sizes:["S","M","L","XL","XXL"], badge:"top", seller:"BIBAOfficial", category:"kurti" },
  { id:3, brand:"Roadster", name:"Men Regular Fit Cotton T-Shirt", price:249, mrp:599, off:58, rating:4.2, reviews:"34.1k", img:"https://images.unsplash.com/photo-1521572163474-6864f9cf17ab?w=300&h=380&fit=crop", sizes:["S","M","L","XL"], badge:"fast", seller:"Myntra", category:"men" },
  { id:4, brand:"Shree", name:"Women Silk Blend Saree With Blouse", price:799, mrp:2499, off:68, rating:4.4, reviews:"5.6k", img:"https://images.unsplash.com/photo-1595777457583-95e059d581b8?w=300&h=380&fit=crop", sizes:["Free Size"], badge:"new", seller:"ShreeFashion", category:"kurti" },
  { id:5, brand:"H&M", name:"Women Floral Midi Dress", price:999, mrp:2499, off:60, rating:4.1, reviews:"9.8k", img:"https://images.unsplash.com/photo-1623609163859-ca93c959b98a?w=300&h=380&fit=crop", sizes:["XS","S","M","L"], badge:"trending", seller:"HMIndia", category:"western" },
  { id:6, brand:"Allen Solly", name:"Men Slim Fit Formal Shirt", price:699, mrp:1599, off:56, rating:4.6, reviews:"22.3k", img:"https://images.unsplash.com/photo-1602810318383-e386cc2a3ccf?w=300&h=380&fit=crop", sizes:["S","M","L","XL","XXL"], badge:"top", seller:"AllenSolly", category:"men" },
  { id:7, brand:"Mast & Harbour", name:"Women Regular Fit Hoodie", price:799, mrp:1799, off:56, rating:4.3, reviews:"7.2k", img:"https://images.unsplash.com/photo-1556821840-3a63f15732ce?w=300&h=380&fit=crop", sizes:["XS","S","M","L","XL"], badge:"new", seller:"M&H", category:"western" },
  { id:8, brand:"Puma", name:"Men Running Sports Shoes", price:1999, mrp:4999, off:60, rating:4.4, reviews:"15.7k", img:"https://images.unsplash.com/photo-1542291026-7eec264c27ff?w=300&h=380&fit=crop", sizes:["6","7","8","9","10","11"], badge:"fast", seller:"PumaIndia", category:"bags" },
  { id:9, brand:"Fabindia", name:"Handloom Cotton Lehenga Choli", price:1299, mrp:3499, off:63, rating:4.5, reviews:"3.4k", img:"https://images.unsplash.com/photo-1591234275010-8a4e4b8f2e7a?w=300&h=380&fit=crop", sizes:["S","M","L","XL"], badge:"top", seller:"Fabindia", category:"kurti" },
  { id:10, brand:"Fossil", name:"Analog Watch Brown Dial", price:2999, mrp:6995, off:57, rating:4.7, reviews:"4.8k", img:"https://images.unsplash.com/photo-1523275335684-37898b6baf30?w=300&h=380&fit=crop", sizes:["One Size"], badge:"trending", seller:"FossilIndia", category:"jewellery" },
  { id:11, brand:"Levi's", name:"Men Slim Fit Mid Rise Jeans", price:1499, mrp:3499, off:57, rating:4.4, reviews:"28.6k", img:"https://images.unsplash.com/photo-1541099649105-f69ad21f3246?w=300&h=380&fit=crop", sizes:["28","30","32","34","36"], badge:"fast", seller:"LevisIndia", category:"men" },
  { id:12, brand:"Bobbi Brown", name:"Long Wear Cream Shadow", price:449, mrp:999, off:55, rating:4.2, reviews:"6.7k", img:"https://images.unsplash.com/photo-1512496015851-a90fb38ba796?w=300&h=380&fit=crop", sizes:["One Size"], badge:"new", seller:"BobbiOfficial", category:"beauty" },
];

const addons = [
  { name:"Gold Earrings", price:199, img:"https://images.unsplash.com/photo-1535632066927-ab7c9ab60908?w=150&h=180&fit=crop" },
  { name:"Silk Dupatta", price:299, img:"https://images.unsplash.com/photo-1583591532536-cbf3e91c0d29?w=150&h=180&fit=crop" },
  { name:"Potli Bag", price:349, img:"https://images.unsplash.com/photo-1548036328-c9fa89d128fa?w=150&h=180&fit=crop" },
  { name:"Bangles Set", price:149, img:"https://images.unsplash.com/photo-1535632066927-ab7c9ab60908?w=150&h=180&fit=crop" },
  { name:"Kajal Liner", price:99, img:"https://images.unsplash.com/photo-1512496015851-a90fb38ba796?w=150&h=180&fit=crop" },
];

// ========== STATE ==========
let cart = [];
let wishlist = new Set();
let compareItems = [];
let activeFilters = {};
let recentlyViewed = [];
let currentSlide = 0;
let slideTimer;

// ========== INIT ==========
document.addEventListener('DOMContentLoaded', () => {
  initSkeletonLoad();
  initBannerSlider();
  initSearchBar();
  initPriceSlider();
  initDarkMode();
  initScrollEvents();
  renderAddons();
  duplicateTicker();
});

function duplicateTicker() {
  const inner = document.querySelector('.ticker-inner');
  if (inner) {
    const clone = inner.cloneNode(true);
    inner.parentElement.appendChild(clone);
  }
}

// ========== SKELETON LOAD ==========
function initSkeletonLoad() {
  setTimeout(() => {
    document.getElementById('skeletonGrid').style.display = 'none';
    const grid = document.getElementById('productGrid');
    grid.style.display = 'grid';
    renderProducts(products);
  }, 1400);
}

// ========== RENDER PRODUCTS ==========
function renderProducts(list) {
  const grid = document.getElementById('productGrid');
  grid.innerHTML = '';
  list.forEach((p, i) => {
    const card = createProductCard(p, i);
    grid.appendChild(card);
  });
}

function createProductCard(p, i) {
  const div = document.createElement('div');
  div.className = 'product-card';
  div.style.animationDelay = `${i * 0.06}s`;

  const badgeMap = {
    trending: ['badge-trending','🔥 Trending'],
    fast: ['badge-fast','⚡ Fast Selling'],
    new: ['badge-new','✨ New'],
    top: ['badge-top','💎 Top Rated'],
  };
  const [badgeClass, badgeText] = badgeMap[p.badge] || ['',''];

  const isWished = wishlist.has(p.id);
  const ratingColor = p.rating >= 4 ? '#27ae60' : p.rating >= 3 ? '#f39c12' : '#e74c3c';

  div.innerHTML = `
    <div class="card-img-wrap" onclick="openQuickView(${p.id})">
      <img src="${p.img}" alt="${p.name}" loading="lazy"/>
      ${badgeClass ? `<span class="card-badge ${badgeClass}">${badgeText}</span>` : ''}
      <div class="card-actions">
        <button class="card-action-btn ${isWished?'wishlisted':''}" id="wish-${p.id}" onclick="event.stopPropagation();toggleWishlist(${p.id})" title="Wishlist">
          <i class="fa${isWished?'s':'r'} fa-heart"></i>
        </button>
        <button class="card-action-btn" onclick="event.stopPropagation();openQuickView(${p.id})" title="Quick View">
          <i class="fas fa-eye"></i>
        </button>
        <button class="card-action-btn" onclick="event.stopPropagation();addCompare(${p.id})" title="Compare">
          <i class="fas fa-balance-scale"></i>
        </button>
      </div>
      <div class="card-quickview" onclick="openQuickView(${p.id})">
        <i class="fas fa-eye"></i> Quick View
      </div>
    </div>
    <div class="card-body">
      <div class="card-brand">${p.brand}</div>
      <div class="card-name" title="${p.name}">${p.name}</div>
      <div class="card-pricing">
        <span class="card-price">₹${p.price}</span>
        <span class="card-mrp">₹${p.mrp}</span>
        <span class="card-off">${p.off}% off</span>
      </div>
      <div class="card-rating">
        <span class="rating-badge" style="background:${ratingColor}">
          <i class="fas fa-star" style="font-size:9px"></i> ${p.rating}
        </span>
        <span class="rating-count">(${p.reviews})</span>
        <span class="seller-badge"><i class="fas fa-check-circle"></i> ${p.seller}</span>
      </div>
      <div class="card-sizes">
        ${p.sizes.map(s => `<span class="size-chip">${s}<span class="size-tooltip">Size: ${s}<br>Fits ${getSizeFit(s)}</span></span>`).join('')}
      </div>
      <button class="card-add-btn" onclick="addToCart(${p.id})">
        <i class="fas fa-shopping-bag"></i> Add to Cart
      </button>
      <div class="compare-check-wrap">
        <input type="checkbox" id="cmp-${p.id}" onchange="toggleCompare(${p.id}, this.checked)"/>
        <label for="cmp-${p.id}">Compare</label>
      </div>
    </div>
  `;
  return div;
}

function getSizeFit(s) {
  const map = { XS:'28-30"', S:'30-32"', M:'32-34"', L:'34-36"', XL:'36-38"', XXL:'38-40"' };
  return map[s] || 'Standard';
}

// ========== QUICK VIEW ==========
function openQuickView(id) {
  const p = products.find(x => x.id === id);
  if (!p) return;

  // Add to recently viewed
  if (!recentlyViewed.find(x => x.id === id)) {
    recentlyViewed.unshift(p);
    if (recentlyViewed.length > 6) recentlyViewed.pop();
    renderRecentlyViewed();
  }

  const ratingColor = p.rating >= 4 ? '#27ae60' : '#f39c12';
  document.getElementById('qvContent').innerHTML = `
    <img class="qv-img" src="${p.img}" alt="${p.name}"/>
    <div class="qv-info">
      <div class="qv-brand">${p.brand}</div>
      <h2 class="qv-name">${p.name}</h2>
      <div class="qv-price">₹${p.price}</div>
      <div class="qv-mrp">MRP ₹${p.mrp}</div>
      <div class="qv-off">${p.off}% OFF — You save ₹${p.mrp - p.price}!</div>
      <div class="qv-rating">
        <span class="rating-badge" style="background:${ratingColor}"><i class="fas fa-star" style="font-size:9px"></i> ${p.rating}</span>
        <span class="rating-count">${p.reviews} ratings</span>
      </div>
      <div style="margin-bottom:8px;font-size:13px;color:var(--text-muted);font-family:var(--font-label)">SELECT SIZE</div>
      <div class="qv-sizes">
        ${p.sizes.map(s => `<div class="qv-size-chip" onclick="selectSize(this)">${s}</div>`).join('')}
      </div>
      <div style="margin-bottom:12px;font-size:12px;color:var(--text-muted);font-family:var(--font-ui)">
        <i class="fas fa-truck" style="color:var(--primary)"></i> Free Delivery • 
        <i class="fas fa-undo" style="color:var(--primary)"></i> 7 Day Return • 
        <i class="fas fa-check-circle" style="color:#27ae60"></i> ${p.seller}
      </div>
      <button class="qv-add-btn" onclick="addToCart(${p.id});closeQuickView()">
        <i class="fas fa-shopping-bag"></i> Add to Bag
      </button>
    </div>
  `;
  document.getElementById('quickViewOverlay').classList.add('active');
}

function closeQuickView() {
  document.getElementById('quickViewOverlay').classList.remove('active');
}

function selectSize(el) {
  el.closest('.qv-sizes').querySelectorAll('.qv-size-chip').forEach(c => c.classList.remove('active'));
  el.classList.add('active');
}

// ========== WISHLIST ==========
function toggleWishlist(id) {
  const btn = document.getElementById(`wish-${id}`);
  if (wishlist.has(id)) {
    wishlist.delete(id);
    btn.classList.remove('wishlisted');
    btn.innerHTML = '<i class="far fa-heart"></i>';
  } else {
    wishlist.add(id);
    btn.classList.add('wishlisted');
    btn.innerHTML = '<i class="fas fa-heart"></i>';
    btn.classList.add('wish-burst');
    setTimeout(() => btn.classList.remove('wish-burst'), 400);
  }
}

// ========== CART ==========
function addToCart(id) {
  const p = products.find(x => x.id === id);
  if (!p) return;
  const existing = cart.find(x => x.id === id);
  if (existing) {
    existing.qty++;
  } else {
    cart.push({ ...p, qty: 1 });
  }
  updateCartUI();
  bounceCart();
  renderCartItems();
}

function updateCartUI() {
  const count = cart.reduce((a, b) => a + b.qty, 0);
  document.getElementById('cartCount').textContent = count;
  document.getElementById('cartBadge').textContent = count;
}

function bounceCart() {
  const fc = document.getElementById('floatingCart');
  fc.classList.add('bounce');
  setTimeout(() => fc.classList.remove('bounce'), 500);
}

function renderCartItems() {
  const el = document.getElementById('cartItems');
  if (cart.length === 0) {
    el.innerHTML = `<div class="empty-cart"><i class="fas fa-shopping-bag"></i><p>Your cart is empty</p><button onclick="closeCart()">Continue Shopping</button></div>`;
    document.getElementById('cartFooter').style.display = 'none';
    return;
  }
  document.getElementById('cartFooter').style.display = 'block';
  let total = 0;
  el.innerHTML = cart.map(item => {
    total += item.price * item.qty;
    return `
      <div class="cart-item">
        <img class="cart-item-img" src="${item.img}" alt="${item.name}"/>
        <div class="cart-item-info">
          <div class="cart-item-name">${item.name}</div>
          <div class="cart-item-price">₹${item.price}</div>
          <div class="cart-item-qty">
            <button class="qty-btn" onclick="changeQty(${item.id},-1)">−</button>
            <span class="qty-num">${item.qty}</span>
            <button class="qty-btn" onclick="changeQty(${item.id},1)">+</button>
          </div>
        </div>
        <button class="cart-item-remove" onclick="removeFromCart(${item.id})"><i class="fas fa-trash"></i></button>
      </div>
    `;
  }).join('');
  document.getElementById('cartTotal').textContent = total.toLocaleString('en-IN');
}

function changeQty(id, delta) {
  const item = cart.find(x => x.id === id);
  if (!item) return;
  item.qty += delta;
  if (item.qty <= 0) removeFromCart(id);
  else { updateCartUI(); renderCartItems(); }
}

function removeFromCart(id) {
  cart = cart.filter(x => x.id !== id);
  updateCartUI(); renderCartItems();
}

function openCart() {
  renderCartItems();
  document.getElementById('cartOverlay').classList.add('active');
}

function closeCart() {
  document.getElementById('cartOverlay').classList.remove('active');
}

document.getElementById('cartBtn').addEventListener('click', openCart);
document.getElementById('floatingCart').addEventListener('click', openCart);

// ========== ADDONS ==========
function renderAddons() {
  const el = document.getElementById('addonScroll');
  el.innerHTML = addons.map(a => `
    <div class="addon-card" onclick="addAddonToCart('${a.name}',${a.price},'${a.img}')">
      <img src="${a.img}" alt="${a.name}"/>
      <div class="addon-info">
        <div class="addon-name">${a.name}</div>
        <div class="addon-price">₹${a.price}</div>
      </div>
    </div>
  `).join('');
}

function addAddonToCart(name, price, img) {
  const id = Date.now();
  cart.push({ id, name, price, qty: 1, img, brand:'Add-on', sizes:[] });
  updateCartUI(); renderCartItems(); bounceCart();
}

// ========== COMPARE ==========
function toggleCompare(id, checked) {
  if (checked) {
    if (compareItems.length >= 3) {
      alert('You can compare up to 3 products only.');
      document.getElementById(`cmp-${id}`).checked = false;
      return;
    }
    compareItems.push(id);
  } else {
    compareItems = compareItems.filter(x => x !== id);
  }
  updateCompareBar();
}

function addCompare(id) {
  const cb = document.getElementById(`cmp-${id}`);
  if (cb) { cb.checked = true; toggleCompare(id, true); }
}

function updateCompareBar() {
  const bar = document.getElementById('compareBar');
  if (compareItems.length > 0) {
    bar.style.display = 'flex';
    document.getElementById('compareCount').textContent = compareItems.length;
  } else {
    bar.style.display = 'none';
  }
}

function compareProducts() {
  const items = compareItems.map(id => products.find(p => p.id === id)).filter(Boolean);
  if (items.length < 2) { alert('Select at least 2 products to compare.'); return; }
  const table = document.getElementById('compareTable');
  table.innerHTML = items.map(p => `
    <div class="compare-col">
      <img src="${p.img}" alt="${p.name}"/>
      <h3>${p.name}</h3>
      <div class="compare-attr"><span>Brand</span><span>${p.brand}</span></div>
      <div class="compare-attr"><span>Price</span><span>₹${p.price}</span></div>
      <div class="compare-attr"><span>MRP</span><span>₹${p.mrp}</span></div>
      <div class="compare-attr"><span>Discount</span><span>${p.off}% OFF</span></div>
      <div class="compare-attr"><span>Rating</span><span>⭐ ${p.rating}</span></div>
      <div class="compare-attr"><span>Reviews</span><span>${p.reviews}</span></div>
      <div class="compare-attr"><span>Seller</span><span>${p.seller}</span></div>
    </div>
  `).join('');
  document.getElementById('compareOverlay').classList.add('active');
}

function clearCompare() {
  compareItems = [];
  document.querySelectorAll('[id^="cmp-"]').forEach(cb => cb.checked = false);
  updateCompareBar();
}

function closeCompare() {
  document.getElementById('compareOverlay').classList.remove('active');
}

// ========== RECENTLY VIEWED ==========
function renderRecentlyViewed() {
  const sec = document.getElementById('recentlyViewed');
  const scroll = document.getElementById('rvScroll');
  if (recentlyViewed.length === 0) { sec.style.display = 'none'; return; }
  sec.style.display = 'block';
  scroll.innerHTML = recentlyViewed.map(p => `
    <div class="rv-item" onclick="openQuickView(${p.id})">
      <img src="${p.img}" alt="${p.name}"/>
    </div>
  `).join('');
}

// ========== BANNER SLIDER ==========
function initBannerSlider() {
  startSlideTimer();
}

function startSlideTimer() {
  clearInterval(slideTimer);
  slideTimer = setInterval(nextSlide, 4500);
}

function goToSlide(n) {
  const slides = document.querySelectorAll('.banner-slide');
  const dots = document.querySelectorAll('.dot');
  slides[currentSlide].classList.remove('active');
  dots[currentSlide].classList.remove('active');
  currentSlide = (n + slides.length) % slides.length;
  slides[currentSlide].classList.add('active');
  dots[currentSlide].classList.add('active');
  startSlideTimer();
}

function nextSlide() { goToSlide(currentSlide + 1); }
function prevSlide() { goToSlide(currentSlide - 1); }

// ========== SEARCH BAR ==========
function initSearchBar() {
  const input = document.getElementById('searchInput');
  const suggestions = document.getElementById('searchSuggestions');
  const trendingTerms = ['Saree under ₹299', 'Kurti Set', 'Men Casual Shirts', 'Party Wear Dress', 'Gold Plated Earrings'];

  const siEl = document.getElementById('suggestionItems');
  siEl.innerHTML = trendingTerms.map(t => `
    <div class="suggestion-item" onclick="setSearch('${t}')">
      <i class="fas fa-fire"></i> ${t}
    </div>
  `).join('');

  input.addEventListener('focus', () => suggestions.classList.add('active'));
  input.addEventListener('blur', () => setTimeout(() => suggestions.classList.remove('active'), 200));
  input.addEventListener('input', (e) => {
    const val = e.target.value.toLowerCase();
    if (val.length > 1) {
      const filtered = products.filter(p => p.name.toLowerCase().includes(val) || p.brand.toLowerCase().includes(val));
      siEl.innerHTML = filtered.slice(0,5).map(p => `
        <div class="suggestion-item" onclick="setSearch('${p.name}')">
          <i class="fas fa-search"></i> ${p.name} — <strong>₹${p.price}</strong>
        </div>
      `).join('') || '<div class="suggestion-item"><i class="fas fa-info-circle"></i> No results found</div>';
    }
  });

  document.getElementById('voiceBtn').addEventListener('click', openVoice);
  document.getElementById('imageBtn').addEventListener('click', openImageSearch);
}

function setSearch(term) {
  document.getElementById('searchInput').value = term;
  document.getElementById('searchSuggestions').classList.remove('active');
}

// ========== VOICE SEARCH ==========
function openVoice() {
  document.getElementById('voiceOverlay').classList.add('active');
  const SpeechRecognition = window.SpeechRecognition || window.webkitSpeechRecognition;
  if (SpeechRecognition) {
    const recognition = new SpeechRecognition();
    recognition.lang = 'en-IN';
    recognition.onresult = (e) => {
      const transcript = e.results[0][0].transcript;
      document.getElementById('voiceText').textContent = `"${transcript}"`;
      setTimeout(() => {
        setSearch(transcript);
        closeVoice();
      }, 1000);
    };
    recognition.onerror = () => {
      document.getElementById('voiceText').textContent = 'Could not hear. Try again.';
    };
    recognition.start();
  } else {
    document.getElementById('voiceText').textContent = 'Voice search not supported in this browser.';
    document.getElementById('voiceSub') && (document.getElementById('voiceSub').textContent = '');
  }
}

function closeVoice() {
  document.getElementById('voiceOverlay').classList.remove('active');
  document.getElementById('voiceText').textContent = 'Listening...';
}

// ========== IMAGE SEARCH ==========
function openImageSearch() {
  document.getElementById('imgSearchOverlay').classList.add('active');
}

function closeImageSearch() {
  document.getElementById('imgSearchOverlay').classList.remove('active');
}

function handleImageUpload(e) {
  const file = e.target.files[0];
  if (!file) return;
  const reader = new FileReader();
  reader.onload = (ev) => {
    document.getElementById('imgUploadArea').innerHTML = `
      <img src="${ev.target.result}" style="width:100%;height:160px;object-fit:contain;border-radius:8px;margin-bottom:12px;"/>
      <p style="font-family:var(--font-body);font-size:14px;color:var(--text-muted)">Searching similar products...</p>
    `;
    setTimeout(() => {
      closeImageSearch();
      alert('Image search: Showing similar products! (Feature powered by AI in production)');
    }, 2000);
  };
  reader.readAsDataURL(file);
}

// ========== PRICE SLIDER ==========
function initPriceSlider() {
  const minR = document.getElementById('minRange');
  const maxR = document.getElementById('maxRange');
  if (!minR || !maxR) return;

  function updateSlider() {
    let min = parseInt(minR.value), max = parseInt(maxR.value);
    if (min > max - 100) { min = max - 100; minR.value = min; }
    document.getElementById('minVal').textContent = min.toLocaleString('en-IN');
    document.getElementById('maxVal').textContent = max.toLocaleString('en-IN');
    const pct1 = ((min - 100) / (10000 - 100)) * 100;
    const pct2 = ((max - 100) / (10000 - 100)) * 100;
    document.getElementById('rangeTrack').style.setProperty('--left', pct1 + '%');
    document.getElementById('rangeTrack').style.setProperty('--right', pct2 + '%');
    addFilterChip(`Price`, `₹${min}–₹${max}`, 'price');
  }

  minR.addEventListener('input', updateSlider);
  maxR.addEventListener('input', updateSlider);
  updateSlider();
}

function setPrice(min, max) {
  document.getElementById('minRange').value = min;
  document.getElementById('maxRange').value = max;
  document.getElementById('minRange').dispatchEvent(new Event('input'));
}

// ========== FILTER CHIPS ==========
function addFilterChip(label, value, key) {
  activeFilters[key] = { label, value };
  renderFilterChips();
}

function renderFilterChips() {
  const bar = document.getElementById('filterChipsBar');
  const container = document.getElementById('activeChips');
  const keys = Object.keys(activeFilters);
  if (keys.length === 0) { bar.style.display = 'none'; return; }
  bar.style.display = 'flex';
  container.innerHTML = keys.map(k => `
    <span class="filter-chip">
      ${activeFilters[k].label}: ${activeFilters[k].value}
      <span class="remove" onclick="removeFilter('${k}')">✕</span>
    </span>
  `).join('');
}

function removeFilter(key) {
  delete activeFilters[key];
  renderFilterChips();
}

function clearAllFilters() {
  activeFilters = {};
  renderFilterChips();
  document.querySelectorAll('.color-option input').forEach(cb => cb.checked = false);
  document.querySelectorAll('[name="discount"]').forEach(r => r.checked = false);
}

function addColorFilter(cb) {
  if (cb.checked) {
    addFilterChip('Color', cb.value, 'color_' + cb.value);
  } else {
    removeFilter('color_' + cb.value);
  }
}

// ========== FILTER TOGGLE ==========
function toggleFilter(name) {
  const body = document.getElementById(`${name}-body`);
  const icon = document.getElementById(`${name}-icon`);
  body.classList.toggle('collapsed');
  icon.style.transform = body.classList.contains('collapsed') ? 'rotate(180deg)' : 'rotate(0deg)';
}

// ========== DARK MODE ==========
function initDarkMode() {
  const saved = localStorage.getItem('meesho-theme') || 'light';
  document.documentElement.setAttribute('data-theme', saved);
  updateDarkIcon(saved);
}

document.getElementById('darkToggle').addEventListener('click', () => {
  const current = document.documentElement.getAttribute('data-theme');
  const next = current === 'dark' ? 'light' : 'dark';
  document.documentElement.setAttribute('data-theme', next);
  localStorage.setItem('meesho-theme', next);
  updateDarkIcon(next);
});

function updateDarkIcon(theme) {
  const icon = document.getElementById('darkIcon');
  icon.className = theme === 'dark' ? 'fas fa-sun' : 'fas fa-moon';
}

// ========== SCROLL EVENTS ==========
function initScrollEvents() {
  window.addEventListener('scroll', () => {
    const btt = document.getElementById('backToTop');
    if (window.scrollY > 400) btt.classList.add('visible');
    else btt.classList.remove('visible');
  });
  document.getElementById('backToTop').addEventListener('click', () => {
    window.scrollTo({ top: 0, behavior: 'smooth' });
  });
}

// ========== THEME CUSTOMIZER ==========
function toggleCustomizer() {
  const panel = document.getElementById('customizerPanel');
  panel.style.display = panel.style.display === 'none' ? 'block' : 'none';
}

function setTheme(primary, light) {
  document.documentElement.style.setProperty('--primary', primary);
  document.documentElement.style.setProperty('--primary-light', light);
  document.querySelectorAll('.swatch').forEach(s => s.classList.remove('active'));
  event.target.classList.add('active');
}

// ========== NOTIFICATION ==========
document.getElementById('notifBtn').addEventListener('click', (e) => {
  e.stopPropagation();
  document.getElementById('notifDropdown').classList.toggle('active');
});
document.addEventListener('click', () => {
  document.getElementById('notifDropdown').classList.remove('active');
});

// ========== NAV CATEGORY ==========
document.querySelectorAll('.nav-item').forEach(item => {
  item.addEventListener('click', () => {
    document.querySelectorAll('.nav-item').forEach(i => i.classList.remove('active'));
    item.classList.add('active');
  });
});

// ========== TAG PILLS ==========
document.querySelectorAll('.tag-pill').forEach(pill => {
  pill.addEventListener('click', () => {
    document.getElementById('searchInput').value = pill.textContent;
  });
});
