//funcion tipo clase
function MyModal(idModal, idOpener=null) {

  const $modal = document.getElementById(idModal)
  if(!$modal) return console.log("no modal found!")

  const $dialog = $modal.querySelector(":scope > [role='modal-dialog']")
  const $title = $dialog.querySelector(":scope > header > [role='title']")
  const $btnClose = $dialog.querySelector(":scope > header > [role='btn-close']")
  const $body = $dialog.querySelector(":scope > [role='body']")
  const $opener = idOpener ? document.getElementById(idOpener) : null

//  const show = () => {
//    $modal.classList.remove("modal-hide")
//    $modal.classList.add("modal-show")
//  }

  const hide = () => $modal.classList.add("modal-hide")

  function show(fnBefore, fnAfter) {
    if (fnBefore) {
      const abort = fnBefore()
      if (abort) return this
    }

    show()
    if(fnAfter) fnAfter()
    return this
  }

  this.hide = function (fnBefore, fnAfter) {
    if (fnBefore) {
      const abort = fnBefore()
      if (abort) return this
    }
    hide()
    if(fnAfter) fnAfter()
    return this
  }

  function set_body(html) {
    if(!html || !$body) return this
    $body.innerHTML = html
    return this
  }

  function set_title(html) {
    if(!html || !$title) return this
    $title.innerHTML = html
    return this
  }

  this.destroy = () => {
    if($modal) $modal.removeEventListener("click", hide)
    if($opener) $opener.removeEventListener("click", show)
    if($btnClose) $btnClose.removeEventListener("click", hide)
    if($title) $title.innerHTML = ""
    if($body) $body.innerHTML = ""
    return null
  }

  (() => {
    //configuro los listeners
    $modal.addEventListener("click", hide)
    if ($dialog) $dialog.addEventListener("click", e => e.stopPropagation())
    if ($opener) $opener.addEventListener("click", show)
    if ($btnClose) $btnClose.addEventListener("click", hide)
  })()

}//MyModal
